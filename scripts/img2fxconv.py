import os
import sys
from PIL import Image

meta = ""
cFile = """
#include <gint/display.h>

struct image {
  int xOffset;
  int yOffset;
  const bopti_image_t *data;
};
"""
header = "struct image;\n"

# Crop all the transparency around the image and return the x and y offset
def crop(orig_path, new_path):
  img = Image.open(orig_path)
  img = img.convert("RGBA")
  outData = []

  # Crop step
  # Create a copy of the image with transparent pixels set to black, and non-transparent pixels set to white.
  # This is used so that getbbox() can be used to crop out the transparent pixels.
  newImg = img.copy()
  for x in range(newImg.size[0]):
    for y in range(newImg.size[1]):
      if newImg.getpixel((x, y))[3] < 128:
        newImg.putpixel((x, y), (0, 0, 0, 0))
      else:
        newImg.putpixel((x, y), (255, 255, 255, 255))
  box = newImg.getbbox()

  # Crop the image to the box.
  img = img.crop(box)

  # Save the image
  img.save(new_path)

  return box[0], box[1]

# Loop over the PNG files in ../assets/img/ (relative to the script)
os.chdir(os.path.dirname(os.path.realpath(__file__)))
for file in os.listdir("../assets/img/"):
  if file.endswith(".png"):
    # Crop and copy to ../assets-cg/
    x, y = crop("../assets/img/" + file, "../assets-cg/" + file)
    meta += f"{file}:\n"
    meta += f"  type: bopti-image\n"
    meta += f"  name: b_{file.split('.')[0]}\n"
    cFile += f"extern const bopti_image_t b_{file.split('.')[0]};\n"
    cFile += f"const struct image internal_img_{file.split('.')[0]} = {{ {x}, {y}, &b_{file.split('.')[0]} }};\n"
    cFile += f"const struct image* img_{file.split('.')[0]} = &internal_img_{file.split('.')[0]};\n"
    header += f"extern const struct image* img_{file.split('.')[0]};\n"
    print("Converted " + file)
  # If it's a directory, create an array containing the header for each image in the directory.
  elif os.path.isdir("../assets/img/" + file):
    dataArray = []
    for n in range(9999):
      # Check if n.png exists, and exit the loop if it doesn't.
      subFile = f"../assets/img/{file}/{n}.png"
      if not os.path.isfile(subFile):
        break
      # Crop and copy to ../assets-cg/filename_n.png
      x, y = crop(subFile, f"../assets-cg/{file}_{n}.png")
      meta += f"{file}_{n}.png:\n"
      meta += f"  type: bopti-image\n"
      meta += f"  name: b_{file.split('.')[0]}_{n}\n"
      meta += f"  profile: p8\n"
      print("Converting " + subFile)
      cFile += f"extern const bopti_image_t b_{file.split('.')[0]}_{n};\n"
      cFile += f"const struct image internal_img_{file.split('.')[0]}_{n} = {{ {x}, {y}, &b_{file.split('.')[0]}_{n} }};\n"
      cFile += f"const struct image* img_{file.split('.')[0]}_{n} = &internal_img_{file.split('.')[0]}_{n};\n"
      header += f"extern const struct image* img_{file.split('.')[0]}_{n};\n"
    # Array that combines all the images in the directory
    cFile += f"const struct image* imgs_{file.split('.')[0]}[{n}] = {{"
    for i in range(n):
      cFile += f"  &internal_img_{file.split('.')[0]}_{i}, "
    cFIle = cFile[:-2] + "};\n"
    cFile += f"}};\n"
    header += f"extern const struct image* imgs_{file.split('.')[0]}[{n}];\n"
    print("Converted " + file)
  else:
    print("Skipping " + file)

with open("../assets-cg/fxconv-metadata.txt", "w") as f:
  f.write(meta)

with open("../data-headers/images-fxconv.c", "w") as f:
  f.write(cFile)

with open("../data-headers/images-fxconv.h", "w") as f:
  f.write(header)
