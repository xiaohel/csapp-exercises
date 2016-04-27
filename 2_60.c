#include <stdio.h>

unsigned int replace_bype(unsigned int x, unsigned char b, int i) {
  unsigned char *ucp = (unsigned char *)&x;
  ucp[i] = b;
  return x;
}

int main(int argc, char const *argv[])
{
  unsigned int x = 0x12345678;
  unsigned char b = 0xAB;
  int i = 2;
  printf("0x%X\n", replace_bype(x, b, i));

  i = 0;
  printf("0x%X\n", replace_bype(x, b, i));

  return 0;
}
/*
uname -a
Darwin MacBook-Pro 15.0.0 Darwin Kernel Version 15.0.0: Sat Sep 19 15:53:46 PDT 2015; root:xnu-3247.10.11~1/RELEASE_X86_64 x86_64
gcc -o main 2_60.c
./main
0x12AB5678
0x123456AB
*/
