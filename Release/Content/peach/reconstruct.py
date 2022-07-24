from PIL import Image
from zopfli.zlib import compress
import sys

# Read track.dat
with open("track.dat", "rb") as f:
  track = f.read()

# # Compress it
# zopfli_encoded = compress(track, numiterations=20)

# print(f"Zopfli length: {len(zopfli_encoded)}")

# compressedTrack = "const unsigned char compressedTrack[] = {"
# for byte in zopfli_encoded:
#   compressedTrack += f"0x{byte:02x}, "
# compressedTrack = compressedTrack[:-2] + "};"
# compressedTrack += "\n"
# compressedTrack += f"const int compressedTrackSize = {len(zopfli_encoded)};"

# Open tileset.png
tileset = Image.open("tileset.png")
# Round the width down to a multiple of 8 and crop it
tileset = tileset.crop((0, 0, tileset.width - (tileset.width % 8), tileset.height))
# Split it into widthx8 strips and make them into one long image
tileset_strips = []
for i in range(0, tileset.height, 8):
  tileset_strips.append(tileset.crop((0, i, tileset.width, i + 8)))
longImage = Image.new("RGBA", (tileset.width * len(tileset_strips), 8))
for i in range(len(tileset_strips)):
  longImage.paste(tileset_strips[i], (i * tileset.width, 0))
# Crop starting at tile number 512 and make it 256*8 wide
longImage = longImage.crop((512 * 8, 0, 512 * 8 + 256 * 8, 8))
# Save it as tileset_long.png
longImage.save("tileset_long.png")

# Reformat it into a 128x128 image, with 16 tiles per row
squareImage = Image.new("RGBA", (128, 128))
for i in range(16):
  # Paste a 128x8 tile at the correct position
  squareImage.paste(longImage.crop((i * 128, 0, i * 128 + 128, 8)), (0, i * 8))
# Save it as tileset_square.png
squareImage.save("tileset_square.png")

# Now save the 240th tile of the tileset as tile_240.png
tileNum = 240
tile_240 = longImage.crop((tileNum * 8, 0, tileNum * 8 + 8, 8))
tile_240.save("tile_240.png")

# Split into a 256x256 array of tiles
tiles = []
for i in range(0, len(track), 256):
  # print(tiles)
  tiles.append(track[i:i+256])

# print(tiles)

# Create the image
img = Image.new("RGB", (256 * 8, 256 * 8))

# Fill in the tiles
for x in range(256):
  for y in range(256):
    tile = tiles[x][y]
    # Get the tile from the tileset
    tileImg = longImage.crop((tile * 8, 0, tile * 8 + 8, 8))
    # Rotate it by 90 degrees and flip it
    tileImg = tileImg.transpose(Image.Transpose.ROTATE_90)
    tileImg = tileImg.transpose(Image.Transpose.FLIP_TOP_BOTTOM)
    if (tile >= 240 and tile <= 243) or (tile >= 208 and tile <= 215):
      # Tint it red
      redToBlend = Image.new("RGBA", (8, 8))
      redToBlend.paste((255, 0, 0, 255), (0, 0, 8, 8))
      # Blend it with the tile
      tileImg = Image.blend(tileImg, redToBlend, 0.5)
    # Paste it into the image
    img.paste(tileImg, (x * 8, y * 8))

# Save the image
img.save("track.png")

# track = "const unsigned short tileData[256][256] = {\n"
# for tileNum in range(256):
#   track += "  {"
#   # Get the tile from the tileset
#   tileImg = longImage.crop((tileNum * 8, 0, tileNum * 8 + 8, 8))
#   # Rotate it by 90 degrees and flip it
#   tileImg = tileImg.transpose(Image.Transpose.ROTATE_90)
#   tileImg = tileImg.transpose(Image.Transpose.FLIP_TOP_BOTTOM)
#   # Loop over the pixels
#   for x in range(8):
#     for y in range(8):
#       # Get the pixel colour
#       r, g, b, a = tileImg.getpixel((x, y))
#       # Convert to RGB565.
#       rgb = ((r & 0b11111000) << 8) | ((g & 0b11111100) << 3) | (b >> 3)
#       # Add it to the track
#       track += f"0x{rgb:04x}, "
#   track = track[:-2] + "},\n"
# track += "};\n"

# track += "#define trackImageWidth 256 * 8\n"
# track += "#define trackImageHeight 256 * 8\n"

# with open("track.h", "w") as f:
#   f.write(track)
