import rle
import zlib
import json
from zopfli.zlib import compress

with open("./track.json", "r") as f:
  track = json.load(f)

# Array of numbers
# print(track)

# RLE encode it
rle_track = rle.encode(track)

# zlib compress it
# First, convert to bytes (each number is a byte)
bytes = b""
for number in track:
  bytes += number.to_bytes(1, byteorder='big')

encoded = zlib.compress(bytes, level=9)
zopfli_encoded = compress(bytes, numiterations=20)

print(f"Original length: {len(track)}")
print(f"RLE length: {len(rle_track[0]) + len(rle_track[1])}")
print(f"Zlib length: {len(encoded)}")
print(f"Zopfli  length: {len(zopfli_encoded)}")

print("const unsigned char compressedTrack[] = {", end="")
for byte in zopfli_encoded:
  print(f"0x{byte:02x}, ", end="")
print("};")

