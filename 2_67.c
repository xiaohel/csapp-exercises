#include <stdio.h>

/*
 * Yield 1 when int is 32 bits, 0 otherwise. Don't use sizeof.
 * 00000000 00000000 00000000 00000001
 * << 31
 * 10000000 00000000 00000000 00000000
 *
 * 00000000 00000000 00000000 00000001
 * << 32
 * ?
 * The following code does not run properly on some machines
 */
int bad_int_size_32() {
  // Set msb of 32-bit machine
  int set_msb = 1 << 31;

  // Shift pass msb of 32-bit word
  int beyond_msb = 1 << 32;

  printf("set_msb: %x\n", set_msb);
  printf("beyond_msb: %x\n", beyond_msb);

  /*
   * set_msb is nonzero when word size >= 32
   * beyond_msb is zero when word size <= 32
   */
  return set_msb && !beyond_msb;
}

/*
 * A. shift count >= width of type
 */

/*
 * B, Modify the code to run properly on any machine for which data type int is at least 32 bits.
 */
int int_size_32() {
  int set_msb = 1 << 31;
  int beyond_msb = (1 << 31) << 1;
  printf("set_msb: %x\n", set_msb);
  printf("beyond_msb: %x\n", beyond_msb);
  return set_msb && !beyond_msb;
}

/*
 * C, Modify the code to run properly on any machine for which data type int is at least 16 bits.
 */
int int_size_32_16() {
  int set_msb = 1 << 15 << 15 << 1;
  int beyond_msb = 1 << 15 << 1 << 15 << 1;
  printf("set_msb: %x\n", set_msb);
  printf("beyond_msb: %x\n", beyond_msb);
  return set_msb && !beyond_msb;
}

/*
 * 加上printf("set_msb: %x\n", set_msb)，printf("beyond_msb: %x\n", beyond_msb)与不加它们bad_int_size_32的结果是不一样的？？？
 * uname -spm
 * Darwin x86_64 i386
 * gcc --version
 * Configured with: --prefix=/Applications/Xcode.app/Contents/Developer/usr --with-gxx-include-dir=/usr/include/c++/4.2.1
 * Apple LLVM version 7.0.2 (clang-700.1.81)
 * Target: x86_64-apple-darwin15.0.0
 * Thread model: posix
 * gcc -o main 2_67.c
 * 2_67.c:19:22: warning: shift count >= width of type [-Wshift-count-overflow]
 *  int beyond_msb = 1 << 32;
 *                     ^  ~~
 * 1 warning generated.
 * ./main
 * set_msb: 80000000
 * beyond_msb: 8b9dec0
 * bad_int_size_32(): 0
 * set_msb: 80000000
 * beyond_msb: 0
 * int_size_32(): 1
 * set_msb: 80000000
 * beyond_msb: 0
 * int_size_32_16(): 1
 */
int main(void)
{
  printf("bad_int_size_32(): %d\n", bad_int_size_32());
  printf("int_size_32(): %d\n", int_size_32());
  printf("int_size_32_16(): %d\n", int_size_32_16());
  return 0;
}
