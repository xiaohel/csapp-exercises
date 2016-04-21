#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len) {
  int i;
  for (i = 0; i < len; i++) {
    printf("%.2x", start[i]);
  }
  printf("\n");
}

void show_int(int x) {
  show_bytes((byte_pointer)&x, sizeof(int));
}

void show_float(float x) {
  show_bytes((byte_pointer)&x, sizeof(float));
}

void show_pointer(void *x) {
  show_bytes((byte_pointer)&x, sizeof(void *));
}

void test_show_bytes(int val) {
  int ival = val;
  float fval = (float)ival;
  int *pval = &ival;
  show_int(ival);
  show_float(fval);
  show_pointer(pval);
}

int main(void)
{
  int val = 3;
  test_show_bytes(val);
  return 0;
}

/***********************************************************************************************
uname -a
Darwin MacBook-Pro 15.0.0 Darwin Kernel Version 15.0.0: Sat Sep 19 15:53:46 PDT 2015; root:xnu-3247.10.11~1/RELEASE_X86_64 x86_64
gcc -o main show_byte.c
./main
03000000
00004040
c8783259ff7f0000

uname -a
Linux hostname 2.6.39-400.21.1.el6uek.x86_64 #1 SMP Thu Apr 4 03:49:00 PDT 2013 x86_64 x86_64 x86_64 GNU/Linux
gcc -o main show_bytes.c
./main
03000000
00004040
908d84eaff7f0000
***********************************************************************************************/
