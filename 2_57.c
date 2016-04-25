#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len) {
  int i;
  for (i = 0; i < len; i++) {
    printf(" %.2x", start[i]);
  }
  printf("\n");
}

void show_short(short int x) {
  show_bytes((byte_pointer)&x, sizeof(short int));
}

void show_long(long int x) {
  show_bytes((byte_pointer)&x, sizeof(long int));
}

void show_double(double x) {
  show_bytes((byte_pointer)&x, sizeof(double));
}

/*
uname -a
Darwin MacBook-Pro 15.0.0 Darwin Kernel Version 15.0.0: Sat Sep 19 15:53:46 PDT 2015; root:xnu-3247.10.11~1/RELEASE_X86_64 x86_64
gcc -o main 2_57.c
./main
 40 00
 40 00 00 00 00 00 00 00
 00 00 00 00 00 00 50 40
*/
int main(void)
{
  int val = 64;
  short int sval = (short int)val;
  long int lval = (long int)val;
  double dval = (double)val;

  show_short(sval);
  show_long(lval);
  show_double(dval);

  return 0;
}
