with open("behaviour.txt", "r") as f:
  behaviour = f.read().split("\n")[0].split(" ")
  # Convert list of hex strings to list of numbers
  behaviour = [int(x, 16) for x in behaviour]

for n, b in enumerate(behaviour):
  # Print as binary
  print(f"{n}: {bin(b)[2:].zfill(8)}")

offRoadTiles = [0, 3, 4, 7, 8, 9, 10, 12, 13, 14, 15, 17, 33, 48, 49, 50, 51, 52, 53, 64, 67, 68, 69, 80, 96, 152, 168, 200, 201, 218]

num = 0xff
for n in offRoadTiles:
  num = num & behaviour[n]

# Print as binary
print(f"{bin(num)[2:].zfill(8)}")

# Count the amount of unique numbers in the list
uniqueNumbers = set()
for n in behaviour:
  uniqueNumbers.add(n)
print(len(uniqueNumbers))
