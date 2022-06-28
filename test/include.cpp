#include "./test.cpp"
#include <stdio.h>

int main() {
  image test = include_image("test.png");
  printf("%p\n", test);
  return 0;
}
