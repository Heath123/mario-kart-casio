#include "./data.h"
#include "./miniz.h"

#include "../data-headers/compressedTrack.h"

#include <stdlib.h>

// extern unsigned char* compressedTrack;
// extern int compressedTrackSize;
unsigned char* trackData;

void initData() {
  mz_ulong trackDataSize = 256 * 256;
  trackData = malloc(trackDataSize);
  uncompress(trackData, &trackDataSize, compressedTrack, compressedTrackSize);
}
