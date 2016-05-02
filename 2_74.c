#include <stdio.h>
#include <limits.h>

/* Determine whether arguments can be subtracted without overflow
 * 跟2.73类似
 */
int tsub_ok(int x, int y) {
  int a = x;
  int b = ~y + 1;
  int sum = a + b;
  int positive_overflow = !(a & INT_MIN) && !(b & INT_MIN) && (sum & INT_MIN);
  int negative_overflow = (a & INT_MIN) && (b & INT_MIN) && !(sum & INT_MIN);

  return !positive_overflow && !negative_overflow;
}

int main(void)
{
  printf("tsub_ok(%d, %d): %d\n", 1, 1024, tsub_ok(1, 1024));
  printf("tsub_ok(%d, %d): %d\n", INT_MIN, 1, tsub_ok(INT_MIN, 1));
  printf("tsub_ok(%d, %d): %d\n", INT_MIN, INT_MAX, tsub_ok(INT_MIN, INT_MAX));
  printf("tsub_ok(%d, %d): %d\n", INT_MAX, -1, tsub_ok(INT_MAX, -1));
  printf("tsub_ok(%d, %d): %d\n", INT_MAX, INT_MAX, tsub_ok(INT_MAX, INT_MAX));
  return 0;
}
