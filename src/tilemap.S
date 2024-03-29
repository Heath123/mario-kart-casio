.global _getTileID
.type _getTileID, @function 

_getTileID: # (r4: xPos, r5: yPos) -> r0
        mov     r4, r0
        or      r5, r0
        shlr8   r0
        tst     #0b11111000, r0
        # T is now 0 if we want to return 0
        bf     .return0
        # otherwise, continue
        mov     #-3, r1
        shad    r1, r4
        shad    r1, r5
        # multiply r5 by 256
        shll8   r5
        add     r5, r4
        # read from the tilemap
        mov.l .tilemap, r0
        # now r0 = _tilemap symbol = address of the variable, which is an array
        # shll2 r4
        mov.b @(r0, r4), r0
        rts
        extu.b r0, r0
.return0:
        rts
        mov    #0, r0
# .align 4
# .tilemap:
#         .long _tilemap

# extern unsigned char tileset[256][64];
# extern unsigned short palette[256];
# extern unsigned char tilemap[256 * 256];
#
# unsigned short __attribute__ ((hot)) samplePixel(int xPos, int yPos) {
#   xPos += xOffset;
#   yPos += yOffset;
#
#   // Divide by 4
#   xPos = xPos >> 2;
#   yPos = yPos >> 2;
#
#   // Get the position of the pixel in the tile
#   int xPixelInTile = xPos & (8 - 1);
#   int yPixelInTile = yPos & (8 - 1);
#
#   // Get the colour of the pixel in the tile
#   unsigned char tileID = getTileID(xPos, yPos);
#   unsigned char index = tileset[tileID][(yPixelInTile * 8) + xPixelInTile];
#   return palette[index];
# }

.global _samplePixel
.type _samplePixel, @function

_samplePixel: # (r4: xPos, r5: yPos) -> r0
        # TODO: When inlining this into the loop, we can make sure to only do these loads once if we have the registers available
        # add xOffset to xPos
        mov.l .xOffset, r1
        mov.w   @r1, r1
        add     r1, r4
        # add yOffset to yPos
        mov.l .yOffset, r1
        mov.w   @r1, r1
        add     r1, r5
        # divide by 4
        shlr2   r4
        shlr2   r5
        # get the position of the pixel in the tile
        # copy them into other registers so we can use the original ones for the tileID
        mov     r4, r6
        mov     #0b111, r0
        and     r0, r6
        mov     r5, r7
        and     r0, r7
        # get the colour of the pixel in the tile
        # get the tile ID by calling getTileID
        # Inlined version of getTileID


        mov     r4, r0
        or      r5, r0
        shlr8   r0
        tst     #0b11111000, r0
        # T is now 0 if we want to return 0
        bf     .return0v2
        # otherwise, continue
        mov     #-3, r1
        shad    r1, r4
        shad    r1, r5
        # multiply r5 by 256
        shll8   r5
        add     r5, r4
        # read from the tilemap
        mov.l .tilemap, r0
        # now r0 = _tilemap symbol = address of the variable, which is an array
        # shll2 r4
        mov.b @(r0, r4), r0
        bra .end
        extu.b r0, r0
.return0v2:
        # rts
        mov    #0, r0
.end:



        # r0 now contains the tile ID
        # multiply r7 by 8
        # Happens in branch delay slot
        shll2   r7
        add     r7, r7
        # add r6 to r7
        add     r6, r7
        # multiply r0 by 64
        shll8   r0
        shlr2   r0
        # add r0 to r7
        add     r0, r7
        # read from the tileset
        mov.l .tileset, r0
        # now r0 = _tileset symbol = address of the variable, which is an array
        mov.b @(r0, r7), r0
        extu.b r0, r0
        # read from the palette
        mov.l .palette, r1
        # now r1 = _palette symbol = address of the variable, which is an array
        # multiply r0 by 2
        add    r0, r0
        # read from the palette
        mov.w @(r0, r1), r0
        rts
        extu.w r0, r0

# void draw3DLine(int x, int y, int dx, int dy, int y2,/*, unsigned int* vramLine*/) {
#   for (unsigned short x2 = 0; x2 < 198; x2++) {
#     color_t col = samplePixel(x >> 16, y >> 16);
#     *vramLine = (col << 16 | col);
#     vramLine++;
# 
#     x += dx;
#     y += dy;
#   }
# }

.global _draw3DLine
.type _draw3DLine, @function

_draw3DLine: # (r4: x, r5: y, r6: dx, r7: dy) -> r0
# vramLine is stored in a global because I don't want to deal with loading it from the stack
        # Save registers
        mov.l r8,@-r15
        mov.l r9,@-r15
        mov.l r10,@-r15
        mov.l r11,@-r15
        mov.l r12,@-r15
        mov.l r13,@-r15
        mov.l r14,@-r15

        # Copy dx and dy into r13 and r14 (otherwise they get overwritten)
        mov r6, r13
        mov r7, r14

        # Load vramLine into r8
        mov.l .vramLine, r8
        mov.l  @r8, r8

        # Load xOffset into r12
        mov.l .xOffset, r12
        mov.w   @r12, r12

        # Load yOffset into r2
        mov.l .yOffset, r2
        mov.w   @r2, r2

        # Use r9 as the loop counter
        # Load 198 into it and go backwards
        # Counting down is better because we only have to load the value of 198 once
        mov.w .halfWidth, r9
.loop:
        # Set r10 to x >> 16
        swap.w  r4, r10
        exts.w  r10, r10
        # Set r11 to y >> 16
        swap.w  r5, r11
        exts.w  r11, r11
        # Call samplePixel

        # START: INLINED VERSION OF samplePixel
        # (though I made some changes to it to optimize it)
        # add xOffset to xPos
        add     r12, r10
        # add yOffset to yPos
        add     r2, r11
        # divide by 4
        shlr2   r10
        mov     #0b111, r0
        shlr2   r11
        # get the position of the pixel in the tile
        # copy them into other registers so we can use the original ones for the tileID
        mov     r10, r6
        and     r0, r6
        mov     r11, r7
        and     r0, r7
        # get the colour of the pixel in the tile
        # get the tile ID by calling getTileID

        # START: INLINED VERSION OF getTileID
        # (also with some changes to optimize it)
        mov     r10, r0
        or      r11, r0
        shlr8   r0
        tst     #0b11111000, r0
        # T is now 0 if we want to return 0
        bf.s   .endv2
        mov    #0, r0
        # otherwise, continue
        mov     #-3, r1
        shad    r1, r10
        shad    r1, r11
        # now r0 = _tilemap symbol = address of the variable, which is an array
        mov.l .tilemap, r0
        # multiply r11 by 256
        shll8   r11
        add     r11, r10
        # read from the tilemap
        # shll2 r10
        mov.b @(r0, r10), r0
        bra .endv2
        extu.b r0, r0
.endv2:
        # END: INLINED VERSION OF getTileID

        # r0 now contains the tile ID
        # multiply r7 by 8
        # Happens in branch delay slot
        mov #3, r1
        shad r1, r7
        # add r6 to r7
        add     r6, r7
        # multiply r0 by 64
        mov #6, r1
        shad r1, r0
        # add r0 to r7
        add     r0, r7
        # read from the tileset
        mov.l .tileset, r0
        # now r0 = _tileset symbol = address of the variable, which is an array
        mov.b @(r0, r7), r0
        # read from the palette
        mov.l .palette, r1
        extu.b r0, r0
        # now r1 = _palette symbol = address of the variable, which is an array
        # multiply r0 by 2
        add    r0, r0
        # read from the palette
        mov.w @(r0, r1), r0
        extu.w r0, r0
        # END: INLINED VERSION OF samplePixel

        # Set r1 to the result
        mov r0, r1
        # Shift r1 left by 16
        shll16 r1
        # OR r1 with r0
        or r0, r1
        # Store r12 in vramLine
        mov.l r1, @r8
        # Decrement the loop counter and check if it's 0
        dt r9
        # Increment vramLine
        add #4, r8
        # Increment x by dx
        add r13, r4
        bf.s .loop
        # Increment y by dy (branch delay slot)
        add r14, r5

        # Restore registers
        mov.l @r15+,r14
        mov.l @r15+,r13
        mov.l @r15+,r12
        mov.l @r15+,r11
        mov.l @r15+,r10
        mov.l @r15+,r9
        rts
        mov.l @r15+,r8
.align 2
.halfWidth:
        .word 198
.align 4
.vramLine:
        .long _vramLine
.align 4
.xOffset:
        .long _xOffset
.align 4
.yOffset:
        .long _yOffset
.align 4
.tilemap:
        .long _tilemap
.align 4
.tileset:
        .long _tileset
.align 4
.palette:
        .long _palette