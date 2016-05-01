#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * 因为sizeof的返回值类型是unsigned，maxbytes会被自动转换成unsigned进行运算，结果也是unsigned的。
 * 相当于((unsigned)maxbytes - sizeof(val)) % UINT_MAX + 1。所以结果肯定是 >= 0的。
 */
void copy_int_buggy(int val, void *buf, int maxbytes) {
  if (maxbytes - sizeof(val) >= 0)
    memcpy(buf, (void *) &val, sizeof(val));
}

/*
 * 将size_t强制转换为int就可以了
 */
void copy_int(int val, void *buf, int maxbytes) {
  if (maxbytes - (int)sizeof(val) >= 0) {
    printf("Going to copy.\n");
    memcpy(buf, (void *) &val, sizeof(val));
  } else {
    printf("Won't copy.\n");
  }
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
 * gcc -o main 2_72.c
 * 2_72.c:10:30: warning: comparison of unsigned expression >= 0 is always true
 *       [-Wtautological-compare]
 *   if (maxbytes - sizeof(val) >= 0)
 *       ~~~~~~~~~~~~~~~~~~~~~~ ^  ~
 * 1 warning generated.
 *
 * ./main
 * Going to copy.
 * Won't copy.
 */
int main(void)
{
  void *buf = malloc(1 * sizeof(int));
  int val = -1;
  copy_int(val, buf, 4);
  copy_int(val, buf, 3);
  free(buf);
  buf = NULL;
  return 0;
}
