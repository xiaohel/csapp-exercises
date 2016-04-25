#include <stdio.h>

int is_big_endian() {
  unsigned int x = 0x01234567;
  char *c = (char*) &x;
  if (*c == 0x10) {
    return 1;
  } else {
    return 0;
  }
}

/*
uname -a
Darwin MacBook-Pro 15.0.0 Darwin Kernel Version 15.0.0: Sat Sep 19 15:53:46 PDT 2015; root:xnu-3247.10.11~1/RELEASE_X86_64 x86_64
gcc -o main 2_58.c
./main
Little Endian.
*/
int main (void)
{
  if (is_big_endian())
    printf ("Big Endian.\n");
  else
    printf ("Little Endian.\n");

  return 0;
}
