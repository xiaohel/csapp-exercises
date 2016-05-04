#include <stdio.h>
/*
 * K = 17   (x << 4) + x
 * K = -7   x - (x << 3)
 * K = 60   (x << 6) - (x << 2)
 * K = -112 (x << 4) - (x << 7)
 */
int main(void)
{
  int x = 10;
  int K = 17;
  printf("%d\n", K * x);
  printf("%d\n", (x << 4) + x);
  K = -7;
  printf("%d\n", K * x);
  printf("%d\n", x - (x << 3));
  K = 60;
  printf("%d\n", K * x);
  printf("%d\n", (x << 6) - (x << 2));
  K = -112;
  printf("%d\n", K * x);
  printf("%d\n", (x << 4) - (x << 7));
  return 0;
}
