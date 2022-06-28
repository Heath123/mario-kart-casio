struct RGBAQUAD
{
  char Red;
  char Green;
  char Blue;
  char Alpha;
};

int main(char r, char g, char b, char a) {
  RGBAQUAD test;
  test.Red = r;
  test.Green = g;
  test.Blue = b;
  test.Alpha = a;

  int rgba = (test.Red << 24) | (test.Green << 16) | (test.Blue << 8) | test.Alpha;
  return rgba;
}
