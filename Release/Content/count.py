from PIL import Image

# Open tileset_long.png
tileset = Image.open("tileset_long.png")
tileset = tileset.convert("RGBA")
# Count the number of unique colours
uniqueColours = set()
for x in range(tileset.width):
  for y in range(tileset.height):
    colour = tileset.getpixel((x, y))
    uniqueColours.add(colour)
# Print the number of unique colours
print(len(uniqueColours))
print(uniqueColours)
