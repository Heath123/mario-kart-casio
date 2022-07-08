import json

# Read compile_commands.json
with open('compile_commands.json', 'r') as f:
  data = json.load(f)

for item in data:
  # Remove -m4-nofpu, -mb and -fstrict-volatile-bitfields
  item["command"] = item["command"].replace("-m4-nofpu", "")