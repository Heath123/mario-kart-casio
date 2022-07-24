from PIL import Image
import json

# Read palette.pal
palette = []
with open("palette.pal", "rb") as f:
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
  print("Number of colours:", num_colours)
  for i in range(num_colours):
    # 4 bytes (RGBA)
    r, g, b, a = f.read(4)
    palette.append((r, g, b, 255))

# Check if there are any duplicate colours
if len(set(palette)) != len(palette):
  raise Exception("Duplicate colours in palette")

rgb565_palette = []
for i in range(len(palette)):
  r, g, b, a = palette[i]
  rgb = ((r & 0b11111000) << 8) | ((g & 0b11111100) << 3) | (b >> 3)
  rgb565_palette.append(rgb)

with open("palette.json", "w") as f:
  json.dump(rgb565_palette, f)

# Read tileset.dat
with open('tileset.dat', 'rb') as f:
  tileset = f.read()

image = Image.new('P', (8 * 16, 8 * 16))

flat_palette = []
for i in range(len(palette)):
  r, g, b, a = palette[i]
  flat_palette.append(r)
  flat_palette.append(g)
  flat_palette.append(b)

image.putpalette(flat_palette)

count = 0
for y in range(16):
  for x in range(16):
    for y1 in range(8):
      for x1 in range(8):
        image.putpixel((x * 8 + x1, y * 8 + y1), tileset[count])
        count += 1

# Save as a PNG
image.save('tileset.png')
