#include <stdio.h>
#include <limits.h>

/*
 * 5*x/8其实就是((x << 2) + x) >> 3，但是5*x有可能会溢出，或者x < 0的时候，使用移位操作会导致不是向0舍入
 * 所以需要向divide_power2那么处理
 */
int mul5div8(int x) {
  int m = (x << 2) + x;
  int sign = !!(m & INT_MIN);
  sign && (m = (m + 8 - 1));
  return m >> 3;
}

int expected(int x) {
  return 5 * x / 8;
}

int main(void)
{
  printf("  expected\t  mul5div8\n");
  int x = 0;
  printf("%10d\t%10d\n", expected(x), mul5div8(x));
  x = INT_MAX;
  printf("%10d\t%10d\n", expected(x), mul5div8(x));
  x = INT_MIN;
  printf("%10d\t%10d\n", expected(x), mul5div8(x));
  x = 10;
  printf("%10d\t%10d\n", expected(x), mul5div8(x));
  x = -10;
  printf("%10d\t%10d\n", expected(x), mul5div8(x));
  x = 1;
  printf("%10d\t%10d\n", expected(x), mul5div8(x));
  x = -1;
  printf("%10d\t%10d\n", expected(x), mul5div8(x));
  x = 12340;
  printf("%10d\t%10d\n", expected(x), mul5div8(x));
  x = -12340;
  printf("%10d\t%10d\n", expected(x), mul5div8(x));
  return 0;
}
