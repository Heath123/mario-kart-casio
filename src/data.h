#ifndef _DATA_H
#define _DATA_H

#include "./platform.h"

#include <stdbool.h>

// https://github.com/thomasgoldstein/epicedit/blob/0a48fc/EpicEdit/Rom/Tracks/Road/RoadTileGenre.cs
enum TileType {
  JumpBar = 0x10,
  // Edge of Choco Island road bump
  BumpEdge = 0x12,
  ItemBlock = 0x14,
  BoostPad = 0x16,
  OilSlick = 0x18,
  Coin = 0x1A,
  // Choco Island road bump
  Bump = 0x1C,
  WoodPlank = 0x1E,
  // Air where you fall off the road (e.g. on Rainbow Road)
  Empty = 0x20,
  Water = 0x22,
  Lava = 0x24,
  OutOfBounds = 0x26,
  // Empty border that delimits the road and the void, on Rainbow Road
  EmptyBorder = 0x28,
  Road = 0x40,
  // Ghost Valley plank intersection
  PlankJunction = 0x42,
  BrickRoad = 0x44,
  Clay = 0x46,
  WetSand = 0x48,
  SoftSand = 0x4A,
  RoughClay = 0x4C,
  FlatSurface = 0x4E,
  Bridge = 0x50,
  SlipperyRoad = 0x52,
  Sand = 0x54,
  Offroad = 0x56,
  Snow = 0x58,
  Grass = 0x5A,
  ShallowWater = 0x5C,
  Mud = 0x5E,
  // Boundary that can't be driven through or jumped over
  SolidBlock = 0x80,
  // Breaks when hit
  FrailBlock = 0x82,
  // Also breaks when hit
  IceBlock = 0x84
};

typedef struct {
  const unsigned char* compressedTileset;
  int compressedTilesetSize;
  const unsigned char (*tileset)[64];
  const unsigned short* palette;
  const unsigned char* compressedTilemap;
  int compressedTilemapSize;
  const unsigned char* tilemap;
  const unsigned char* tileTypes;
  int startX;
  int startY;
  // color_t skyColor;
  const struct image* bg;
  bool fullBg;
  bool drawLoop;
} trackData;

extern trackData track;
extern unsigned char tileset[256][64];
extern unsigned short palette[256];
extern unsigned char tilemap[256 * 256];

void initData(int trackID);

#endif // _DATA_H
