import subprocess
import os
import sys
import time

file_to_load = "/home/heath/mk-gint/MarioKart.g3a"

def linux_to_winepath(path):
  # We could use winepath but it's slow
  # Use string manipulation instead - less reliable, but much faster
  return 'Z:' + path.replace('/', '\\')


# This uses X11 tools, but is designed to work on Wayland as well because Wine runs under XWayland.

def get_id(name):
  try:
    output = subprocess.check_output(['xdotool', 'search', '--name', name]).decode('utf-8').strip()
  except subprocess.CalledProcessError:
    return None
  if output == '':
    return None
  return output.split('\n')[0]

print('Uploading', file_to_load, 'to simulator...')

win_id = get_id('fx-CG Manager PLUS')

if win_id is None:
  raise Exception('Could not find window. Make sure to have the fx-CG Manager PLUS window open.')

delay = False
def sleep():
  if delay:
    time.sleep(0.5)

# Focus window
subprocess.call(['xdotool', 'windowactivate', win_id])
sleep()

# Alt + L to Open KeyLog menu
# Use ydotool instead of xdotool so it works on Wayland
subprocess.call(['ydotool', 'key', '56:1', '38:1', '38:0'])
sleep()

# E for editor
subprocess.call(['ydotool', 'key', '18:1', '18:0'])
sleep()

# Release Alt and press PgUp
subprocess.call(['ydotool', 'key', '56:0', '104:1', '104:0'])
sleep()

# Alt + L to open KeyLog menu again
subprocess.call(['ydotool', 'key', '56:1', '38:1', '38:0'])
sleep()

# M to switch to emulator
subprocess.call(['ydotool', 'key', '50:1', '50:0'])
sleep()

# L to open KeyLog menu again
subprocess.call(['ydotool', 'key', '38:1', '38:0'])
sleep()

# P for Auto Play and release Alt
subprocess.call(['ydotool', 'key', '25:1', '25:0', '56:0'])
sleep()

# Wait for a window named "Open" to appear
open_id = None
while True:
  open_id = get_id('Open')
  if open_id is not None:
    break
  time.sleep(0.1)

print('Open window found')
sleep()

# Get current keyboard layout
lines = subprocess.check_output(['setxkbmap', '-query']).decode('utf-8').strip().split('\n')
# Find the line starting with "layout:"
layout_line = [line for line in lines if line.startswith('layout:')][0]
# Get the layout name
layout = layout_line.split(' ')[-1]

# Set the layout to "us" so xdotool works
subprocess.call(['setxkbmap', 'us'])

# Type the path to the file
subprocess.call(['xdotool', 'type', linux_to_winepath(file_to_load) + '\r'])
sleep()

# Set the layout back to the original
subprocess.call(['setxkbmap', layout])

print('Done')
