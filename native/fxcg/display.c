/* 
 * compile with 
 * 
 * gcc -o minimal_xcb_shm_image \
 *        minimal_xcb_shm_image.c \
 *     -lxcb -lxcb-image -lxcb-shm
 */
#include <stdlib.h>
#include <stdio.h>

#include <sys/ipc.h>
#include <sys/shm.h>

#include <xcb/xcb.h>
#include <xcb/shm.h>
#include <xcb/xcb_image.h>

#include <string.h>

unsigned short screenarray[384 * 216];
unsigned int screencopy[384 * 216];

#define false 0
#define true 0

#define byte unsigned char

#if __ORDER_LITTLE_ENDIAN == __BYTE_ORDER__
# define NATIVE_XCB_IMAGE_ORDER    XCB_IMAGE_ORDER_LSB_FIRST
#else
# define NATIVE_XCB_IMAGE_ORDER    XCB_IMAGE_ORDER_MSB_FIRST
#endif

enum  {
    IMAGE_WIDTH  = 384,
    IMAGE_HEIGHT = 216,
    IMAGE_DEPTH  = 24,
};

static xcb_format_t const *query_xcb_format_for_depth(
    xcb_connection_t *const connection,
    unsigned depth )
{
    xcb_setup_t const *const setup = xcb_get_setup(connection);
    xcb_format_iterator_t it;
    for( it = xcb_setup_pixmap_formats_iterator(setup)
       ; it.rem
       ; xcb_format_next(&it)
    ){
        xcb_format_t const *const format = it.data;
        if( format->depth == depth ){
            return format;
        }
    }
    return NULL;
}

typedef struct shm_xcb_image_t {
    xcb_connection_t *connection;
    xcb_image_t  *image;
    xcb_shm_seg_t shm_seg;
    int           shm_id;
} shm_xcb_image_t;

static shm_xcb_image_t *shm_xcb_image_create(
    xcb_connection_t *const connection,
    unsigned const width,
    unsigned const height,
    unsigned const depth )
{
    xcb_generic_error_t *error = NULL;

    shm_xcb_image_t *shmimg = calloc(1, sizeof(*shmimg));
    if( !shmimg ){ goto fail; }
    shmimg->connection = connection;

    xcb_format_t const *const format = query_xcb_format_for_depth(connection, depth);
    if( !format ){ goto fail; }
    shmimg->image = xcb_image_create(
        width, height,
        XCB_IMAGE_FORMAT_Z_PIXMAP,
        format->scanline_pad,
        format->depth, format->bits_per_pixel, 0,
        NATIVE_XCB_IMAGE_ORDER,
        XCB_IMAGE_ORDER_MSB_FIRST,
        NULL, ~0, 0);
    if( !shmimg->image ){ goto fail; }

    size_t const image_segment_size = shmimg->image->stride * shmimg->image->height;

    shmimg->shm_id = shmget(IPC_PRIVATE, image_segment_size, IPC_CREAT | 0600);
    if( 0 > shmimg->shm_id ){ goto fail; }

    shmimg->image->data = shmat(shmimg->shm_id, 0, 0);
    if( (void*)-1 == (void*)(shmimg->image->data) ){ goto fail; }

    shmimg->shm_seg = xcb_generate_id(connection),
    error = xcb_request_check(connection,
        xcb_shm_attach_checked(
            connection,
            shmimg->shm_seg, shmimg->shm_id, 0) );
fail:
    if( shmimg ){
        if( shmimg->image ){
            if( shmimg->image->data && error ){
                shmdt(shmimg->image->data);
                shmimg->image->data = NULL;
            }
            if( !shmimg->image->data ){
                shmctl(shmimg->shm_id, IPC_RMID, 0);
                shmimg->shm_id = -1;
            }
        }
        if( 0 > shmimg->shm_id ){
            xcb_image_destroy(shmimg->image);
            shmimg->image = NULL;
        }
        if( !shmimg->image ){
            free(shmimg);
            shmimg = NULL;
        }
    }
    free(error);

    return shmimg;
}

static void shm_xcb_image_destroy(shm_xcb_image_t *shmimg)
{
    xcb_shm_detach(shmimg->connection, shmimg->shm_seg);
    shmdt(shmimg->image->data);
    shmctl(shmimg->shm_id, IPC_RMID, 0);
    xcb_image_destroy(shmimg->image);
    free(shmimg);
}

static void generate_image(
    shm_xcb_image_t *shmimg,
    unsigned t )
{
    for( unsigned j = 0; j < shmimg->image->height; ++j ){
        uint8_t *const line = shmimg->image->data + j * shmimg->image->stride;
        for( unsigned i = 0; i < shmimg->image->width; ++i ){
            unsigned const bytes_per_pixel = shmimg->image->bpp/8;
            uint8_t *pixel = line + i * bytes_per_pixel;

            /* unsigned const r = (i + t);
            unsigned const g = (j + (i >> 8) & 0xFF);
            unsigned const b = (j >> 8) & 0xFF; */

            // Get RGB from screencopy
            unsigned const r = (screencopy[(j * 384) + i]) & 0xFF;
            unsigned const g = (screencopy[(j * 384) + i] >> 8) & 0xFF;
            unsigned const b = (screencopy[(j * 384) + i] >> 16) & 0xFF;

            switch( bytes_per_pixel ){
            case 4: pixel[3] = 0xFF; // fallthrough
            case 3: pixel[2] = r & 0xFF; // fallthrough
            case 2: pixel[1] = g & 0xFF; // fallthrough
            case 1: pixel[0] = b & 0xFF; // fallthrough
            default: break;
            }
        }
    }
}

// int main(int argc, char *argv[])
void set_main_loop(int (*main_loop)(void))
{
    // Open the connection to the X server
    xcb_connection_t *connection = xcb_connect(NULL, NULL);

    // Check that X MIT-SHM is available (should be).
    const xcb_query_extension_reply_t *shm_extension = xcb_get_extension_data(connection, &xcb_shm_id);
    if( !shm_extension || !shm_extension->present ){
        fprintf(stderr, "Query for X MIT-SHM extension failed.\n");
        return 1;
    }

    shm_xcb_image_t *shmimg = shm_xcb_image_create(connection, IMAGE_WIDTH, IMAGE_HEIGHT, IMAGE_DEPTH);
    if( !shmimg ){
        fprintf(stderr, "Creating shared memory image failed");
    }

    // Get the first screen
    xcb_screen_t *const screen = xcb_setup_roots_iterator(xcb_get_setup(connection)).data;

    // Create a window
    uint32_t const window_mask = XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK;
    uint32_t const window_values[] = { screen->white_pixel, XCB_EVENT_MASK_EXPOSURE};
    xcb_drawable_t const window = xcb_generate_id(connection);
    xcb_create_window(connection,
        XCB_COPY_FROM_PARENT,          // depth
        window,                        // window Id
        screen->root,                  // parent window
        0, 0,                          // x, y
        IMAGE_WIDTH, IMAGE_HEIGHT,     // width, height
        0,                             // border_width
        XCB_WINDOW_CLASS_INPUT_OUTPUT, // class
        screen->root_visual,           // visual
        window_mask, window_values     // masks
    );

    // Create black (foreground) graphic context
    xcb_gcontext_t const gc = xcb_generate_id( connection );
    uint32_t const gc_mask = XCB_GC_FOREGROUND | XCB_GC_GRAPHICS_EXPOSURES;
    uint32_t const gc_values[] = {screen->black_pixel, 0};
    xcb_create_gc(connection, gc, window, gc_mask, gc_values);

    // Map the window on the screen and flush
    xcb_map_window(connection, window);
    xcb_flush(connection);

    // Event loop
    unsigned counter = 0;
    /* for( xcb_generic_event_t *event
       ; (event = xcb_wait_for_event(connection))
       ; free(event)
    ){
        switch( event->response_type & ~0x80 ){
        case XCB_EXPOSE:
            generate_image(shmimg, counter++);
            xcb_shm_put_image(connection, window, gc,
                shmimg->image->width, shmimg->image->height, 0, 0,
                shmimg->image->width, shmimg->image->height, 0, 0,
                shmimg->image->depth, shmimg->image->format, 0, 
                shmimg->shm_seg, 0);

            // flush the request
            xcb_flush(connection);
            break;
        default:
            // Unknown event type, ignore it
            break;
        }

    } */

    xcb_intern_atom_cookie_t cookie2 = xcb_intern_atom(connection, 0, 16, "WM_DELETE_WINDOW");
    xcb_intern_atom_reply_t* reply2 = xcb_intern_atom_reply(connection, cookie2, 0);

    while (1)
    {
        main_loop();
        generate_image(shmimg, counter++);
        xcb_shm_put_image(connection, window, gc,
            shmimg->image->width, shmimg->image->height, 0, 0,
            shmimg->image->width, shmimg->image->height, 0, 0,
            shmimg->image->depth, shmimg->image->format, 0, 
            shmimg->shm_seg, 0);

        // flush the request
        xcb_flush(connection);

        // Get any events from the X server
        /* xcb_generic_event_t *event;
        while ((event = xcb_poll_for_event(connection)))
        {
            if((*(xcb_client_message_event_t*)event).data.data32[0] == (*reply2).atom) {
                printf("Window closed\n");
                return;
            }
        } */
        /* xcb_generic_event_t* event;
        while((event = xcb_wait_for_event(connection)))
        {
            puts("Event occurred");
            switch((*event).response_type & ~0x80)
            {
            case XCB_EXPOSE:
                puts("Expose");
                break;
            case XCB_CLIENT_MESSAGE:
            {
                puts("Client Message");
                if((*(xcb_client_message_event_t*)event).data.data32[0] ==
        (*reply2).atom)
                {
                puts("Kill client");
                return 0;
                }
                break;
            }
            }
        } */
    }
    

    shm_xcb_image_destroy(shmimg);

    // return 0;
}

void* GetVRAMAddress(void) {
  // TODO: move setup to the init thing
  // setup();
  // emscripten_set_canvas_size(384, 216);
  return &screenarray;
}

void PrintXY(int x, int y, const char *string, int mode, int color) {
  printf("%s\n", string + 2);
}

void Bdisp_EnableColor(int n) {}

void Bdisp_PutDisp_DD(void) {
  for (int i = 0; i < (384 * 216); i++) {
    int c = screenarray[i];
    // https://gist.github.com/companje/11deb82e807f2cf927b3a0da1646e795#file-rgb565-pde-L8
    byte r = (byte)(((c & 0xF800) >> 11) << 3);
    byte g = (byte)(((c & 0x7E0) >> 5) << 2);
    byte b = (byte)(((c & 0x1F)) << 3);
    unsigned int argb = 0xff000000 | ((int)b << 16) | ((int)g << 8) | (int)r;
    screencopy[i] = argb;
  }
  // Copy_ToCanvas(screencopy);
}

void Bdisp_PutDisp_DD_stripe(int y1, int y2) {
  Bdisp_PutDisp_DD();
}

void Bdisp_AllClr_VRAM(void) {
  /* for (int i = 0; i < (384 * 216); i++) {
    screen[i] = 0xffff;
  } */
  // Optimised version with memset
  memset(screenarray, 0xff, 384 * 216 * 2);
}

void initMock() {}
void PRGM_GetKey_OS( unsigned char*p ) {}
