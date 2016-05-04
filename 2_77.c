#include <stdio.h>
#include <limits.h>

/* Divide by power of two.  Assume 0 <= k < w-1
 * 参考CSAPP原书第二版2.3.7小节：Dividing by Powers of Two
 * 还真是有点难得到这个式子：((x < 0 ? x + (1 << k) -1 : x)) >> k
 */
int divide_power2(int x, int k) {
  int sign = !!(x & INT_MIN);
  sign && (x = (x + (1 << k) - 1));
  return x >> k;
}

int main(void)
{
  int x = -12340;
  printf("x = %d, k = %d, ans = %d\n", x, 0, divide_power2(x, 0));
  printf("x = %d, k = %d, ans = %d\n", x, 1, divide_power2(x, 1));
  printf("x = %d, k = %d, ans = %d\n", x, 2, divide_power2(x, 2));
  printf("x = %d, k = %d, ans = %d\n", x, 4, divide_power2(x, 4));
  printf("x = %d, k = %d, ans = %d\n", x, 8, divide_power2(x, 8));

  x = 12340;
  printf("x = %d, k = %d, ans = %d\n", x, 0, divide_power2(x, 0));
  printf("x = %d, k = %d, ans = %d\n", x, 1, divide_power2(x, 1));
  printf("x = %d, k = %d, ans = %d\n", x, 2, divide_power2(x, 2));
  printf("x = %d, k = %d, ans = %d\n", x, 4, divide_power2(x, 4));
  printf("x = %d, k = %d, ans = %d\n", x, 8, divide_power2(x, 8));
  return 0;
}
