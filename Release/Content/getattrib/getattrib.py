with open("rom.gba", "rb") as f:
  romBytes = f.read()

trackNames = []
offsets = []

attributes = {
  0x10: "Jump bar",
  0x12: "Bump edge",
  0x14: "Item block",
  0x16: "Zipper",
  0x18: "Oil slick",
  0x1A: "Coin",
  0x1C: "Bump",
  0x1E: "Wood plank",
  0x20: "Empty",
  0x22: "Water",
  0x24: "Lava",
  0x26: "Out of bounds",
  0x28: "Empty border",
  0x40: "Road",
  0x42: "Plank junction",
  0x44: "Brick road",
  0x46: "Clay",
  0x48: "Wet sand",
  0x4A: "Soft sand",
  0x4C: "Rough clay",
  0x4E: "Flat surface",
  0x50: "Bridge",
  0x52: "Slippery road",
  0x54: "Sand",
  0x56: "Offroad",
  0x58: "Snow",
  0x5A: "Grass",
  0x5C: "Shallow water",
  0x5E: "Mud",
  0x80: "Solid block",
  0x82: "Frail block",
  0x84: "Ice block"
}

with open("offsets.csv") as f:
  for line in f:
    trackNames.append(line.split(",")[0])
    # Offset is in hex
    offsets.append(int(line.split(",")[1].strip(), 16))

index = 40
print("Getting attributes for track " + trackNames[index])
# Read 4 bytes at the offset + 136
trackAttributesOffset = romBytes[offsets[index] + 136:offsets[index] + 140]
# Convert to int (little endian)
trackAttributesOffset = int.from_bytes(trackAttributesOffset, byteorder="little")
trackAttributesOffset += offsets[index]
# Get 256 bytes at the offset + 256
trackAttributes = romBytes[trackAttributesOffset:trackAttributesOffset + 256]
taBytes = trackAttributes
# Convert to array of ints (one byte per int)
trackAttributes = [trackAttributes[i] for i in range(len(trackAttributes))]
print(trackAttributes)
# Print them as hex
print([hex(x) for x in trackAttributes])
# Count the number of unique numbers in the list
uniqueNumbers = set()
for n in trackAttributes:
  uniqueNumbers.add(n)
print(len(uniqueNumbers))

# Write taBytes to a file
with open("trackAttributes.dat", "wb") as f:
  f.write(taBytes)
