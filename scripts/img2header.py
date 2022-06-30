# Reads images, converts the colour data to RGB565, and writes it to a header file.
# 0x4fe0 is used as the transparent colour.

from PIL import Image
import sys
import os

def toData(path):
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
  return outData

def dataToHeader(data, filename):
  out = f"const unsigned short img_{filename.split('.')[0]}[{len(data)}] = {{"
  for i in data:
    out += f"0x{i:04x}, "
  out = out[:-2] + "};"
  return out

def multiDataToHeader(dataArray, filename):
  # Check that the lengths of the data arrays are the same.
  for i in range(len(dataArray)):
    if len(dataArray[i]) != len(dataArray[0]):
      raise Exception("Images must have the same dimensions.")
  
  out = f"const unsigned short imgs_{filename}[{len(dataArray)}][{len(dataArray[0])}] = {{"
  for i in range(len(dataArray)):
    out += "{"
    for j in range(len(dataArray[i])):
      out += f"0x{dataArray[i][j]:04x}, "
    out = out[:-2] + "}, "
  out = out[:-2] + "};"
  return out
  

all = ""
# Loop over the PNG files in ../assets/img/ (relative to the script)
os.chdir(os.path.dirname(os.path.realpath(__file__)))
for file in os.listdir("../assets/img/"):
  if file.endswith(".png"):
    result = dataToHeader(toData("../assets/img/" + file), file)
    print("Converted " + file)
    all += result + "\n"
  # If it's a directory, create an array containing the header for each image in the directory.
  elif os.path.isdir("../assets/img/" + file):
    dataArray = []
    for n in range(9999):
      # Check if n.png exists, and exit the loop if it doesn't.
      subFile = f"../assets/img/{file}/{n}.png"
      if not os.path.isfile(subFile):
        break
      print("Converting " + subFile)
      result = toData(subFile)
      dataArray.append(result)
    result = multiDataToHeader(dataArray, file)
    print("Converted " + file)
    all += result + "\n"
  else:
    print("Skipping " + file)
# Write the header to a file.
with open("../data-headers/images.h", "w") as f:
  f.write(all)
