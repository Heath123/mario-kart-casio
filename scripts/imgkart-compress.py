# Reads images, converts the colour data to RGB565, and writes it to a header file.
# 0x4fe0 is used as the transparent colour.

from PIL import Image
import sys
import os

def toData(path):
  img = Image.open(path)
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

  # Reduce palette
  img = img.convert("P", palette=Image.ADAPTIVE, colors=256)
  # img = img.convert("RGBA")

  # Add the height and width to the header.
  outData.append(img.size[0])
  outData.append(img.size[1])

  # Add the offset (the first two elements of box) to the header.
  outData.append(box[0])
  outData.append(box[1])

  # Iterate through the pixels.
  for y in range(img.size[1]):
    for x in range(img.size[0]):
      # # Get the colour data.
      # r, g, b, a = img.getpixel((x, y))
      # # print(r, g, b, a)
      # # Convert to RGB565.
      # rgb = ((r & 0b11111000) << 8) | ((g & 0b11111100) << 3) | (b >> 3);
      # if (rgb == 0x4fe0):
      #   rgb = 0x4fe1
      # if a < 128:
      #   rgb = 0x4fe0
      # outData.append(rgb)
      outData.append(img.getpixel((x, y)))
  return outData

def dataToCFile(data, name):
  header = f"extern const unsigned short img_{name}[{len(data)}];"
  out = f"const unsigned short img_{name}[{len(data)}] = {{"
  for i in data:
    out += f"0x{i:04x}, "
  out = out[:-2] + "};"
  return header, out

# def multiDataToHeader(dataArray, filename):
#   # Check that the lengths of the data arrays are the same.
#   for i in range(len(dataArray)):
#     if len(dataArray[i]) != len(dataArray[0]):
#       raise Exception("Images must have the same dimensions.")
  
#   out = f"const unsigned short imgs_{filename}[{len(dataArray)}][{len(dataArray[0])}] = {{"
#   for i in range(len(dataArray)):
#     out += "{"
#     for j in range(len(dataArray[i])):
#       out += f"0x{dataArray[i][j]:04x}, "
#     out = out[:-2] + "}, "
#   out = out[:-2] + "};"
#   return out

def multiDataToCFile(dataArray, filename):
  result = ""
  header = ""
  for index, data in enumerate(dataArray):
    head, data = dataToCFile(data, f"{filename.split('.')[0]}_{index}")
    result += data + "\n"
    header += head + "\n"
  result += "const unsigned short* imgs_" + filename.split('.')[0] + "[" + str(len(dataArray)) + "] = {"
  for index, data in enumerate(dataArray):
    result += f"img_{filename.split('.')[0]}_{index}, "
  result = result[:-2] + "};"
  header += "extern const unsigned short* imgs_" + filename.split('.')[0] + "[" + str(len(dataArray)) + "];"
  return header, result

os.chdir(os.path.dirname(os.path.realpath(__file__)))

allBytes = b""
for n in range(9999):
  # Check if n.png exists, and exit the loop if it doesn't.
  subFile = f"../assets/img/kart/{n}.png"
  print(subFile)
  if not os.path.isfile(subFile):
    print("No file found.")
    break
  print("Converting " + subFile)
  result = toData(subFile)
  for byte in result:
    allBytes += byte.to_bytes(2, byteorder='big')
  print(f"{len(result) * 2} bytes written.")

  # Cut the height, width and X and Y offsets off
  newResult = result[4:]
  # Count the amount of unique colours in the image.
  uniqueColours = set(newResult)
  print(f"{len(uniqueColours)} unique colours.")
  print("")
  break

print(f"Total bytes: {len(allBytes)}")
from zopfli.zlib import compress
zopfli_encoded = compress(allBytes, numiterations=20)
print(f"Zopfli encoded bytes: {len(zopfli_encoded)}")
print(f"Zopfli compression ratio: {len(allBytes) / len(zopfli_encoded)}")
