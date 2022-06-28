# Reads images, converts the colour data to RGB565, and writes it to a header file.
# 0x4fe0 is used as the transparent colour.

from PIL import Image
import sys
import os

def toHeader(path):
  img = Image.open(path)
  img = img.convert("RGBA")
  outData = []
  # Add the height and width to the header.
  outData.append(img.size[0])
  outData.append(img.size[1])
  # Iterate through the pixels.
  for y in range(img.size[1]):
    for x in range(img.size[0]):
      # Get the colour data.
      r, g, b, a = img.getpixel((x, y))
      # print(r, g, b, a)
      # Convert to RGB565.
      rgb = ((r & 0b11111000) << 8) | ((g & 0b11111100) << 3) | (b >> 3);
      if (rgb == 0x4fe0):
        rgb = 0x4fe1
      if a < 128:
        rgb = 0x4fe0
      outData.append(rgb)
  out = f"const unsigned short img_{os.path.basename(path).split('.')[0]}[{len(outData)}] = {{"
  for i in outData:
    out += f"0x{i:04x}, "
  out = out[:-2] + "};"
  return out

all = ""
# Loop over the PNG files in ../assets/img/ (relative to the script)
os.chdir(os.path.dirname(os.path.realpath(__file__)))
for file in os.listdir("../assets/img/"):
  if file.endswith(".png"):
    result = toHeader("../assets/img/" + file)
    print("Converted " + file)
    all += result + "\n"
  else:
    print("Skipping " + file)
# Write the header to a file.
with open("../data-headers/images.h", "w") as f:
  f.write(all)
