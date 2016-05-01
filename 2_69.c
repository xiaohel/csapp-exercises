#include <stdio.h>

/*
 * Do rotating left shift.  Assume 0 <= n < w
 * Examples when x = 0x12345678 and w = 32: n = 4 -> 0x23456781, n=20 -> 0x67812345
 * 循环左移移位。x << n 拿到左移n位的结果，(~0 & (x >> (w - n -1) >> 1))拿到被移出去的那几位。
 */
unsigned rotate_left(unsigned x, int n) {
  int w = (int)(8 * sizeof(int));
  return (x << n) | (~0 & (x >> (w - n -1) >> 1));
}

/*
 * uname -psm
 * Darwin x86_64 i386
 * gcc --version
 * Configured with: --prefix=/Applications/Xcode.app/Contents/Developer/usr --with-gxx-include-dir=/usr/include/c++/4.2.1
 * Apple LLVM version 7.0.2 (clang-700.1.81)
 * Target: x86_64-apple-darwin15.0.0
 * Thread model: posix
 *
 * gcc -o main 2_69.c
 * ./main
 * 0x23456781
 * 0x67812345
 * 0x12345678
 */
int main(void)
{
  unsigned x = 0x12345678;
  int n = 4;
  printf("0x%X\n", rotate_left(x, n));
  n = 20;
  printf("0x%X\n", rotate_left(x, n));
  n = 0;
  printf("0x%X\n", rotate_left(x, n));
  return 0;
}
