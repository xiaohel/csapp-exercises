#include <stdio.h>

int main(void)
{
  int x;
  // A when any bit of x equals 1 returns 1, 0 otherwise
  printf("Checking A\n");
  x = 10;
  printf("%d\n", (x || 0) && 1);
  x = 0;
  printf("%d\n", (x || 0) && 1);

  // B when any bit of x equals 0 returns 1, 0 otherwise
  printf("Checking B\n");
  x = 10;
  printf("%d\n", (~x || 0) && 1);
  x = -1;
  printf("%d\n", (~x || 0) && 1);

  // C When any bit in the most significant byte of x equals 1 returns 1, 0 otherwise
  printf("Checking C\n" );
  x = 0x76543210;
  printf("%d \n", ((x >> ((sizeof(int) - 1) << 3)) & 0xFF) || 0);
  x = 0x543210;
  printf("%d \n", ((x >> ((sizeof(int) - 1) << 3)) & 0xFF) || 0);

  // D When any bit in the least significant byte of x equals 0 returns 1, 0 otherwise
  printf("Checking D\n");
  x = 0x765432f7;
  printf("%d\n", (~x & 0xFF) || 0);
  x = 0x765432ff;
  printf("%d\n", (~x & 0xFF) || 0);

  return 0;
}

/*
uname -a
Darwin MacBook-Pro 15.0.0 Darwin Kernel Version 15.0.0: Sat Sep 19 15:53:46 PDT 2015; root:xnu-3247.10.11~1/RELEASE_X86_64 x86_64
gcc -o main 2_61.c
./main
Checking A
1
0
Checking B
1
0
Checking C
1
0
Checking D
1
0
*/
