#include <stdio.h>

/* Declaration of data type where 4 bytes are packed
   into an unsigned */
typedef unsigned packed_t;

/* Failed attempt at xbyte
 * 0x765432FF 保存的是8个bit的0x76，0x54，0x32，0x10就是01110110，01010100，00110010，11111111
 * 0xFF本来应该是-1的，使用该函数得到的是0x000000FF = 255，显然是不对的。
 */
int failed_xbyte(packed_t word, int bytenum) {
    return (word >> (bytenum << 3)) & 0xFF;
}

/*
 * 左移(3 - bytenum) * sizeof(int)位让所求的那个整数的符号位到达最高位，再（算术）右移24位就能得到所求整数的32位表示。
 * 需要稍微算一下为什么符号位扩展值不变，正数的时候前面都是0所有好理解，计算下负数的情况。
 */
int xbyte(packed_t word, int bytenum) {
  //转换下类型，不然右移还是当成unsigned右移
  int x = word;
  return x << ((3 - bytenum) << 3) >> 24;
}

void show_xbyte(packed_t x, int bytenum) {
  printf("xbyte(0x%08X,%d) = 0x%08X\n", x, bytenum, xbyte(x,bytenum));
}

/*
 * uname -spm
 * Darwin x86_64 i386
 * gcc --version
 * Configured with: --prefix=/Applications/Xcode.app/Contents/Developer/usr --with-gxx-include-dir=/usr/include/c++/4.2.1
 * Apple LLVM version 7.0.2 (clang-700.1.81)
 * Target: x86_64-apple-darwin15.0.0
 * Thread model: posix
 *
 * gcc -o main 2_71.c
 * ./main
 * xbyte(0x765432FF,0) = 0xFFFFFFFF
 * xbyte(0x765432FF,1) = 0x00000032
 * xbyte(0x765432FF,2) = 0x00000054
 * xbyte(0x765432FF,3) = 0x00000076
 */
int main(void)
{
  show_xbyte(0x765432FF, 0);
  show_xbyte(0x765432FF, 1);
  show_xbyte(0x765432FF, 2);
  show_xbyte(0x765432FF, 3);
  return 0;
}
