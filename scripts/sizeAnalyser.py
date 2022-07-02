import os
import sys
import re

# Analyses the size of arrays in C files and lists them in order of size.

group = r"(?:\[([a-zA-Z0-9_ ]*)\])"
regex = r"^ *(?:const )?([a-zA-Z0-9_ ]*)" + group + ((group + "?") * 3) + r"\n? *\n?=\n? *\n?\{"
regex = re.compile(regex, re.MULTILINE)

sizes = {
  "char": 1,
  "short": 2,
  "int": 4,
  "long": 8,
  "float": 4,
  "double": 8
}

aliases = {
  "angleWidth": 192,
  "totalHeight": 108
}

includedDirectories = [
  "./src/",
  "./data-headers/"
]

os.chdir(os.path.join(os.path.dirname(os.path.realpath(__file__)), "../"))

# Get all the files in the included directories.
files = []
for directory in includedDirectories:
  for file in os.listdir(directory):
    if file.endswith(".c") or file.endswith(".h"):
      files.append(os.path.join(directory, file))

# Read each file and get the size of each array.
arrays = []
for file in files:
  with open(file, "r") as f:
    content = f.read()
  # The first group is the name and type of the array, the rest are the dimensions.
  for match in regex.finditer(content):
    nameAndType = match.group(1)
    name = nameAndType.split(" ")[-1]
    typeName = " ".join(nameAndType.split(" ")[:-1])
    typeSize = sizes[typeName.split("unsigned ")[-1]]

    dimensions = [match.group(i) for i in range(2, len(match.groups()) + 1)]
    # Filter out the None values.
    dimensions = [dimension for dimension in dimensions if dimension is not None]
    # Resolve the aliases.
    for alias in aliases:
      if alias in dimensions:
        dimensions[dimensions.index(alias)] = aliases[alias]
    # Multiply the dimensions together.
    size = typeSize
    for dimension in dimensions:
      size *= int(dimension)
    arrays.append((name, size))

# Sort the arrays by size - biggest to smallest.
arrays.sort(key=lambda x: x[1], reverse=True)
# Print the arrays with human-readable sizes in KB.
for array in arrays:
  print(f"{array[0]}: {array[1] / 1024:.2f} KB")
