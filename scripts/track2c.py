import os
from PIL import Image
from zopfli.zlib import compress

def export_to_tilemap(path):
  tileset = Image.open(path)
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

  # Reformat it into a 128x128 image, with 16 tiles per row
  squareImage = Image.new("RGBA", (128, 128))
  for i in range(16):
    # Paste a 128x8 tile at the correct position
    squareImage.paste(longImage.crop((i * 128, 0, i * 128 + 128, 8)), (0, i * 8))
  # Save it as tileset.png
  squareImage.save(os.path.split(path)[0] + "/tileset.png")
  # Delete the original export
  os.remove(path)

def exportdat_to_tilemap(path):
    # Read palette.pal
  palette = []
  with open(os.path.join(path, "palette.pal"), "rb") as f:
    # b'RIFF'
    if f.read(4) != b'RIFF':
      raise Exception("Invalid palette file")
    # 32-bit size (ignored)
    f.read(4)
    # b'PAL '
    if f.read(4) != b'PAL ':
      raise Exception("Invalid palette file")
    # b'data'
    if f.read(4) != b'data':
      raise Exception("Invalid palette file")
    # 32-bit version (ignored)
    f.read(4)
    # 2 bytes (unknown)
    f.read(2)
    # 16-bit number of colours
    num_colours = int.from_bytes(f.read(2), byteorder="little")
    # print("Number of colours:", num_colours)
    for i in range(num_colours):
      # 4 bytes (RGBA)
      r, g, b, a = f.read(4)
      palette.append(r)
      palette.append(g)
      palette.append(b)

  # Read tileset.dat
  with open(os.path.join(path, "tileset.dat"), "rb") as f:
    tileset = f.read()

  image = Image.new('P', (8 * 16, 8 * 16))
  image.putpalette(palette)

  count = 0
  for y in range(16):
    for x in range(16):
      for y1 in range(8):
        for x1 in range(8):
          image.putpixel((x * 8 + x1, y * 8 + y1), tileset[count])
          count += 1
  
  image.save(os.path.join(path, "tileset.png"))
  os.remove(os.path.join(path, "tileset.dat"))
  os.remove(os.path.join(path, "palette.pal"))

cFile = ""
header = ""

# Loop over the folders in ../assets/track/ (relative to the script)
os.chdir(os.path.dirname(os.path.realpath(__file__)))
for folder in os.listdir("../assets/track/"):
  path = "../assets/track/" + folder
  if os.path.isdir(path):
    print("Converting track " + folder)

    totalTrackSize = 0

    # If export.png exists, convert it to a tilemap
    if os.path.isfile(path + "/export.png"):
      export_to_tilemap(path + "/export.png")
    
    # If tileset.dat and palette.pal exist, convert them to a tilemap
    if os.path.isfile(path + "/tileset.dat") and os.path.isfile(path + "/palette.pal"):
      exportdat_to_tilemap(path)

    # Tileset
    cFile += f"const unsigned char {folder}_tileset[] = {{\n"
    header += f"extern const unsigned char {folder}_tileset[];\n"
    # Open tileset.png, which is a 128x128 image with 16 8x8 tiles in each direction (256 tiles total)
    tileset = Image.open(path + "/tileset.png")
    # Ensure that the colour mode is P
    # # We need it to be in this format from the start to preserve the original palette to do effects with it,
    # so converting won't work fully.
    if tileset.mode != "P":
      # raise Exception("Tileset colour mode is not P")
      tileset = tileset.convert("P")
    tilesetBytes = b''
    # Loop over the tiles in the tileset
    for y in range(16):
      for x in range(16):
        # Get the tile from the tileset
        tile = tileset.crop((x * 8, y * 8, x * 8 + 8, y * 8 + 8))
        # Rotate it by 90 degrees and flip it
        tile = tile.transpose(Image.Transpose.ROTATE_90)
        tile = tile.transpose(Image.Transpose.FLIP_TOP_BOTTOM)
        # Loop over the pixels in the tile
        for i in range(8):
          for j in range(8):
            # Get the pixel
            col = tile.getpixel((i, j))
            # Ensure that the colour is in the range 0-255
            if col > 255:
              raise Exception("Colour index is too high")
            # Add it to the tileset
            tilesetBytes += bytes([col])
    # Compress the tileset
    tilesetBytes = compress(tilesetBytes, numiterations=20)
    # Loop over all the bytes and add them to the array
    for i in range(len(tilesetBytes)):
      cFile += f"0x{tilesetBytes[i]:02x}, "
    cFile = cFile[:-2] + "};\n"
    header += f"const int {folder}_tileset_size = {len(tilesetBytes)};\n"
    totalTrackSize += len(tilesetBytes)

    # Read the palette from the tileset
    palette = tileset.getpalette()
    # Check that the length is equal to 768 (256 * 3)
    if len(palette) != 768:
      raise Exception("Palette length is not 768 (maybe it's the wrong colour mode? Should be RGB)")
    # Convert it to a list of RGB tuples
    palette = [palette[i:i+3] for i in range(0, len(palette), 3)]
    # Make an array of the colours in RGB565 format
    cFile += f"const unsigned short {folder}_palette[256] = {{\n"
    header += f"extern const unsigned short {folder}_palette[256];\n"
    for col in palette:
      r, g, b = col
      rgb = ((r & 0b11111000) << 8) | ((g & 0b11111100) << 3) | (b >> 3)
      cFile += f"0x{rgb:04X}, "
    cFile = cFile[:-2] + "};\n"
    totalTrackSize += (len(palette) / 3) * 2

    # Track tilemap
    cFile += f"const unsigned char {folder}_tilemap[] = {{\n"
    header += f"extern const unsigned char {folder}_tilemap[];\n"
    # Open tilemap.dat
    with open(path + "/tilemap.dat", "rb") as f:
      # Read the tilemap
      tilemap = f.read()
    # Compress the tilemap
    tilemap = compress(tilemap, numiterations=20)
    # Loop over all the bytes and add them to the array
    for i in range(len(tilemap)):
      cFile += f"0x{tilemap[i]:02x}, "
    cFile = cFile[:-2] + "};\n"
    header += f"const int {folder}_tilemap_size = {len(tilemap)};\n"
    totalTrackSize += len(tilemap)

    # Tile attributes
    cFile += f"const unsigned char {folder}_tileattr[256] = {{\n"
    header += f"extern const unsigned char {folder}_tileattr[256];\n"
    # Open tileAttributes.dat
    with open(path + "/tileAttributes.dat", "rb") as f:
      # Read the tile attributes
      tileattr = f.read()
    # Loop over all the bytes and add them to the array
    for i in range(len(tileattr)):
      cFile += f"0x{tileattr[i]:02x}, "
    cFile = cFile[:-2] + "};\n"
    totalTrackSize += len(tileattr)

    print(f"Total track size: {int(totalTrackSize / 1024)} KB")

# Write the C file to ../data-headers/track.c
with open("../data-headers/track.c", "w") as f:
  f.write(cFile)

# Write the header file to ../data-headers/track.h
with open("../data-headers/track.h", "w") as f:
  f.write(header)
