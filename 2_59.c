#include <stdio.h>

int f(int x, int y) {
  return (x & (~0xFF)) | (y & 0xFF);
}

int main(int argc, char const *argv[])
{
  int x = 0x89ABCDEF;
  int y = 0x76543210;
  printf("%X\n", f(x, y));
  return 0;
}
