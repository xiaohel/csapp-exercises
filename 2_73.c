#include <stdio.h>
#include <limits.h>

/*
 * Addition that saturates to TMin or TMax
 * INT_MIN:10000000 00000000 00000000 00000000
 * 可能发生positive overflow的只能两个数都是正数，所有正数和INT_MIN做&运算都是0
 * 发生上溢时符号位会变为1，所以和INT_MIN做&运算一定不会是0
 * 可能发生negative overflow的只能两个数都是负数，所有负数跟INT_MIN做&运算都不是0（因为至少符号位上1&1 = 1）
 * 发生下溢时，符号位一定是0，如下，已经达到INT_MIN后，再加上任何一个负数，符号位一定是0
 *   10000000 00000000 00000000 00000000
 * + 11111111 11111111 11111111 11111111
 * -------------------------------------
 *  101111111 11111111 11111111 11111111
 */
int saturating_add(int x, int y) {
  int sum = x + y;
  int positive_overflow = !(x & INT_MIN) && !(y & INT_MIN) && (sum & INT_MIN);
  int negative_overflow = (x & INT_MIN) && (y & INT_MIN) && !(sum & INT_MIN);

  !positive_overflow || (sum = INT_MAX);
  !negative_overflow || (sum = INT_MIN);

  return sum;
}

/*
 * from https://github.com/darrenhp/Practice/blob/master/csapp/ch02/2_73.c
 */
void show_saturating_add(int x, int y) {
	printf("saturating_add(0x%08X, 0x%08X) = 0x%08X:%d\n",
			x, y, saturating_add(x, y), saturating_add(x, y) );
	printf("%d + %d = %d\n", x, y, x+y);
}

int main(void)
{
  printf("INT_MIN: %d\n", INT_MIN);
  printf("INT_MAX: %d\n", INT_MAX);
  show_saturating_add(0xFFFFFFFF, 0x80000000);
	show_saturating_add(0xFFFFFFFF, 0xFFFFFFFF);
	show_saturating_add(0x7FFFFFF0, 0x0000000F);
	show_saturating_add(0x7FFFFFF5, 0x0000000F);
	show_saturating_add(0x55555555, 0x55555555);
	show_saturating_add(0x55555555, 0x33333333);
	show_saturating_add(0x55555555, 0x23333333);
	show_saturating_add(0x55555555, 0x2FFFFFFF);
  return 0;
}
