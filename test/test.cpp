typedef unsigned short* image;

unsigned short test_image[] = {
  0x12, 0x34, 0x56, 0x78,
};

image include_image(const char* filename) {
  if (filename == "test.png") {
    return test_image;
  }
  return 0x0;
}
