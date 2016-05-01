#include <stdio.h>

/*
 * Mask with least signficant n bits set to 1
 * Examples: n = 6 --> 0x3F, n = 17 --> 0x1FFFF
 * Assume 1 <= n <= w
 * n = 6  -> 00000000 00000000 00000000 00111111
 * n = 17 -> 00000000 00000001 11111111 11111111
 *
 * ~0将所有位都置1，左移n位，再与左移之前的数进行一次异或操作。为了防止n = 32时左移的不定义行为，先左移n - 1，然后再左移一位。
 */
int lower_one_mask(int n) {
  return ~0 ^ ((~0 << (n - 1)) << 1);
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
 * gcc -o main 2_68.c
 * ./main
 * 0x3F
 * 0x1FFFF
 * 0x1
 * 0xFFFFFFFF
 */
int main(void)
{
  printf("0x%X\n", lower_one_mask(6));
  printf("0x%X\n", lower_one_mask(17));
  printf("0x%X\n", lower_one_mask(1));
  printf("0x%X\n", lower_one_mask((int)(8 * sizeof(int))));
  return 0;
}
