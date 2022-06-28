#include "./main.h"

#include "../track.cpp"
#include "../generated_lut.c"

#define precision 8

unsigned char getTileType(short xPos, short yPos) {
  __builtin_expect(xPos < 0 || xPos >= trackImageWidth || yPos < 0 || yPos >= trackImageHeight, 0);
  if (xPos < 0 || xPos >= trackImageWidth || yPos < 0 || yPos >= trackImageHeight) {
    return 0;  // Grass
  } else {
    // Divide by 8
    int xPixel = xPos >> 3;
    int yPixel = yPos >> 3;

    return trackData[((yPixel * (trackImageWidth / precision)) + xPixel) /*% 8192*/];//
  }
}

unsigned short samplePixel(short xPos, short yPos) {
  xPos += xOffset;
  yPos += yOffset;

  // Divide by 4
  xPos = xPos >> 2;
  yPos = yPos >> 2;

  // Get the position of the pixel in the tile
  int xPixelInTile = xPos & (precision - 1);
  int yPixelInTile = yPos & (precision - 1);

  // Get the colour of the pixel in the tile
  return tileData[getTileType(xPos, yPos) /*% 64*/][(yPixelInTile * precision) + xPixelInTile /*% 64*/];
}

// lut = [0, 572, 1144, 1715, 2286, 2856, 3425, 3993, 4560, 5126, 5690, 6252, 6813, 7371, 7927, 8481, 9032, 9580, 10126, 10668, 11207, 11743, 12275, 12803, 13328, 13848, 14364, 14876, 15383, 15886, 16383, 16876, 17364, 17846, 18323, 18794, 19260, 19720, 20173, 20621, 21062, 21497, 21925, 22347, 22762, 23170, 23571, 23964, 24351, 24730, 25101, 25465, 25821, 26169, 26509, 26841, 27165, 27481, 27788, 28087, 28377, 28659, 28932, 29196, 29451, 29697, 29934, 30162, 30381, 30591, 30791, 30982, 31163, 31335, 31498, 31650, 31794, 31927, 32051, 32165, 32269, 32364, 32448, 32523, 32587, 32642, 32687, 32722, 32747, 32762, 32767]
//
// def fpsin(x):
//   x = x % 360
//   if x < 0:
//     x += 360
//   sign = 1 if x < 180 else -1
//   x = x % 180
//   if x > 90:
//     x = 180 - x
//   x = lut[x]
//   return x * sign

// const short lut[91] = {
//   0, 572, 1144, 1715, 2286, 2856, 3425, 3993, 4560, 5126, 5690, 6252, 6813, 7371, 7927, 8481, 9032, 9580, 10126, 10668, 11207, 11743, 12275, 12803, 13328, 13848, 14364, 14876, 15383, 15886, 16383, 16876, 17364, 17846, 18323, 18794, 19260, 19720, 20173, 20621, 21062, 21497, 21925, 22347, 22762, 23170, 23571, 23964, 24351, 24730, 25101, 25465, 25821, 26169, 26509, 26841, 27165, 27481, 27788, 28087, 28377, 28659, 28932, 29196, 29451, 29697, 29934, 30162, 30381, 30591, 30791, 30982, 31163, 31335, 31498, 31650, 31794, 31927, 32051, 32165, 32269, 32364, 32448, 32523, 32587, 32642, 32687, 32722, 32747, 32762, 32767
// };
const short lut[angleWidth] = {
  0, 269, 539, 808, 1078, 1347, 1616, 1885, 2154, 2423, 2692, 2960, 3228, 3497, 3764, 4032, 4299, 4566, 4833, 5099, 5365, 5631, 5896, 6161, 6426, 6690, 6953, 7216, 7479, 7741, 8003, 8264, 8524, 8784, 9043, 9302, 9560, 9818, 10074, 10330, 10586, 10840, 11094, 11348, 11600, 11852, 12102, 12352, 12602, 12850, 13097, 13344, 13590, 13834, 14078, 14321, 14563, 14804, 15044, 15283, 15520, 15757, 15993, 16228, 16461, 16694, 16925, 17155, 17384, 17612, 17839, 18064, 18288, 18511, 18733, 18953, 19173, 19391, 19607, 19822, 20036, 20249, 20460, 20670, 20878, 21085, 21291, 21495, 21697, 21899, 22098, 22297, 22493, 22689, 22882, 23074, 23265, 23454, 23641, 23827, 24011, 24194, 24375, 24554, 24732, 24907, 25082, 25254, 25425, 25594, 25762, 25927, 26091, 26253, 26414, 26572, 26729, 26884, 27037, 27188, 27338, 27486, 27631, 27775, 27917, 28057, 28196, 28332, 28466, 28599, 28730, 28858, 28985, 29109, 29232, 29353, 29472, 29589, 29703, 29816, 29927, 30036, 30142, 30247, 30350, 30450, 30549, 30645, 30739, 30832, 30922, 31010, 31096, 31180, 31262, 31341, 31419, 31494, 31568, 31639, 31708, 31775, 31839, 31902, 31963, 32021, 32077, 32131, 32183, 32232, 32280, 32325, 32368, 32409, 32447, 32484, 32518, 32550, 32580, 32608, 32633, 32656, 32677, 32696, 32713, 32727, 32739, 32749, 32757, 32763, 32766, 32767
};

short fpsin(short x) {
  x = x % ((angleWidth - 1) * 4);
  if (x < 0) {
    x += ((angleWidth - 1) * 4);
  }
  short sign = 1;
  if (x < ((angleWidth - 1) * 2)) {
    sign = 1;
  } else {
    sign = -1;
  }
  x = x % ((angleWidth - 1) * 2);
  if (x > (angleWidth - 1)) {
    x = ((angleWidth - 1) * 2) - x;
  }
  return lut[x] * sign;
}

short fpcos(short x) {
  return fpsin(x + angleWidth);
}

unsigned short getScreenPixel(unsigned short x, unsigned short y) {
  // Use trigonometry to get the position of the track (mode 7 style)
  /* short xPos = (short)(cos(index) * x - sin(index) * y);
  short yPos = (short)(sin(index) * x + cos(index) * y);
  // Get the colour of the pixel in the track
  return samplePixel(xPos, yPos); */

  // Used to indicate framerate
  /* if (x == 0 && y == 0) {
        return angle == 0;
    } */

  // x /= WIDTH_DIVIDER;

  // Temporary for small screen sizes
  /* if (y >= LUT_HEIGHT) return false;
    if (x >= LUT_WIDTH) return false; */

  // If both samples are 0 in the Python, the horizon colour is set but that doesn't seem to be needed

  // return x % 2 == y % 2 ? 0 : 0xFFFF;

  // unsigned short newY;
  // __builtin_expect(x == (int)(LUT_WIDTH / 2), 0);
  
  // if (x < (int)(LUT_WIDTH / 2)) {
  //   y = distortion_correction[x][y - horizon];
  // } else if (x == (int)(LUT_WIDTH / 2)) {
  //   y = y - 1;
  // } else {
  //   y = distortion_correction[(int)(LUT_WIDTH / 2) + ((int)(LUT_WIDTH / 2) - x)][y - horizon];
  // }
  
  int thingX;
  int thingY;
  if ((y - horizon) < sixteenBitHeight) {
    thingX = angles16[0][y - horizon][0];
    thingY = angles16[0][y - horizon][1];
  } else {
    thingX = angles8[0][y - horizon][0];
    thingY = angles8[0][y - horizon][1];
  }
  // Rotate thingX and thingY by x
  // short xPos = (short)(cos(x) * thingX - sin(x) * thingY);
  // short yPos = (short)(sin(x) * thingX + cos(x) * thingY);
  // Fixed point multiplication
  x += angle;
  short xPos = ((thingX * fpcos(x)) >> 16) + ((thingY * fpsin(x)) >> 16);
  short yPos = ((thingY * fpcos(x)) >> 16) - ((thingX * fpsin(x)) >> 16);

  return samplePixel(xPos, yPos);

  // x = 0;
  // index2 = 0;
  // element = 0;

  // unsigned short newY;
  // // __builtin_expect(x == (int)(LUT_WIDTH / 2), 0);
  // if (x < (int)(LUT_WIDTH / 2)) {
  //   newY = distortion_correction[x][y - horizon];
  // } else if (x == (int)(LUT_WIDTH / 2)) {
  //   newY = y - 1;
  // } else {
  //   newY = distortion_correction[(int)(LUT_WIDTH / 2) + ((int)(LUT_WIDTH / 2) - x)][y - horizon];
  // }

  // if ((y - horizon) < sixteenBitHeight) {
  //   // TODO: Remove again? Or remove the similar code in the loop
  //   /* short index = x + angle;
  //   index = mod(index, (angleWidth * 4));
  //   unsigned short element = mod(index, angleWidth); */

  //   if (index2 < angleWidth) {
  //     return samplePixel(
  //         angles16[element % 16][newY - horizon][0],
  //         angles16[element % 16][newY - horizon][1]);
  //   } else if (index2 < angleWidth * 2) {
  //     // Return 90 degree rotated position
  //     return samplePixel(
  //         angles16[element % 16][newY - horizon][1],
  //         -angles16[element % 16][newY - horizon][0]);
  //   } else if (index2 < angleWidth * 3) {
  //     // Return 180 degree rotated position
  //     return samplePixel(
  //         -angles16[element % 16][newY - horizon][0],
  //         -angles16[element % 16][newY - horizon][1]);
  //   } else /*if (index < angleWidth * 4)*/ {
  //     // Return 270 degree rotated position
  //     return samplePixel(
  //         -angles16[element % 16][newY - horizon][1],
  //         angles16[element % 16][newY - horizon][0]);
  //   }

  // } else {
  //   // TODO: no duplicated code?

  //   // TODO: Remove again? Or remove the similar code in the loop
  //   /* short index = x + angle;
  //   index = mod(index, (angleWidth * 4));
  //   unsigned short element = mod(index, angleWidth); */

  //   if (index2 < angleWidth) {
  //     return samplePixel(
  //         angles8[element][newY - horizon - sixteenBitHeight][0],
  //         angles8[element][newY - horizon - sixteenBitHeight][1]);
  //   } else if (index2 < angleWidth * 2) {
  //     // Return 90 degree rotated position
  //     return samplePixel(
  //         angles8[element][newY - horizon - sixteenBitHeight][1],
  //         -angles8[element][newY - horizon - sixteenBitHeight][0]);
  //   } else if (index2 < angleWidth * 3) {
  //     // Return 180 degree rotated position
  //     return samplePixel(
  //         -angles8[element][newY - horizon - sixteenBitHeight][0],
  //         -angles8[element][newY - horizon - sixteenBitHeight][1]);
  //   } else /*if (index < angleWidth * 4)*/ {
  //     // Return 270 degree rotated position
  //     return samplePixel(
  //         -angles8[element][newY - horizon - sixteenBitHeight][1],
  //         angles8[element][newY - horizon - sixteenBitHeight][0]);
  //   }
  // }
}
