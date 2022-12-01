#include "./data.h"
#include "./miniz.h"

// #include "../data-headers/compressedTrack.h"
#include "../data-headers/track.h"
#include "../data-headers/images.h"

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// extern unsigned char* compressedTrack;
// extern int compressedTrackSize;

// unsigned char* trackData;
trackData track;

// Having these fixed in memory (I think) and directly accessible
// (rather than through a pointer in a struct) seems to provide a
// tiny performance gain in the 3D render, and on this hardware
// every frame matters when it makes the difference between 58
// and 60 FPS.
unsigned char tileset[256][64];
unsigned short palette[256];
unsigned char tilemap[256 * 256];

trackData tracks[] = {
  // Peach Circuit
  {
    .compressedTileset = peach_circuit_tileset,
    .compressedTilesetSize = peach_circuit_tileset_size,
    .tileset = 0,
    .palette = peach_circuit_palette,
    .compressedTilemap = peach_circuit_tilemap,
    .compressedTilemapSize = peach_circuit_tilemap_size,
    .tilemap = 0,
    .tileTypes = peach_circuit_tileattr,
    .startX = 3565,
    .startY = 2600,
    .bg = 0,
    .fullBg = false,
    .drawLoop = true,
  },
  // Sunset Wilds
  {
    .compressedTileset = sunset_wilds_tileset,
    .compressedTilesetSize = sunset_wilds_tileset_size,
    .tileset = 0,
    .palette = sunset_wilds_palette,
    .compressedTilemap = sunset_wilds_tilemap,
    .compressedTilemapSize = sunset_wilds_tilemap_size,
    .tilemap = 0,
    .tileTypes = sunset_wilds_tileattr,
    .startX = 7425,
    .startY = 3673,
    .bg = 0,
    .fullBg = false,
    .drawLoop = false,
  },
  // Sky Garden
  {
    .compressedTileset = sky_garden_tileset,
    .compressedTilesetSize = sky_garden_tileset_size,
    .tileset = 0,
    .palette = sky_garden_palette,
    .compressedTilemap = sky_garden_tilemap,
    .compressedTilemapSize = sky_garden_tilemap_size,
    .tilemap = 0,
    .tileTypes = sky_garden_tileattr,
    .startX = 7060,
    .startY = 2900,
    .bg = 0,
    .fullBg = true,
    .drawLoop = false,
  },
};

void initData(int trackID) {
  // mz_ulong trackDataSize = 256 * 256;
  // trackData = malloc(trackDataSize);
  // uncompress(trackData, &trackDataSize, compressedTrack, compressedTrackSize);

  track = tracks[trackID];
  switch (trackID) {
    case 0:
      track.bg = img_bg;
      break;
    case 1:
      track.bg = img_bg_sunset;
      break;
    case 2:
      track.bg = img_skygarden_bg;
      break;
  }

  mz_ulong size;

  // memcpy(tileset, track.compressedTileset, sizeof(tileset));
  size = 256 * 64;
  uncompress(&tileset[0][0], &size, track.compressedTileset, track.compressedTilesetSize);
  track.tileset = tileset;

  memcpy(palette, track.palette, sizeof(palette));
  track.palette = palette;

  // memcpy(tilemap, track.tilemap, sizeof(tilemap));
  size = 256 * 256;
  uncompress(tilemap, &size, track.compressedTilemap, track.compressedTilemapSize);
  track.tilemap = tilemap;
}
