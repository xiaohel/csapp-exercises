#include <stdio.h>

/*
 * Return 1 when any odd bit of x equals 1; 0 otherwise
 */
int any_odd_one(unsigned x) {
  // odd_bits_ones(the 1st bit to the 32nd bit) 01010101 01010101 01010101 01010101 = 0x55555555;
  return (x & 0x55555555) || 0;
}

int main(void)
{
  //10000000 00000000 00000000 00010001
  unsigned int x = 0x80000011;
  printf("%d\n", any_odd_one(x));

  //10101010 10101010 10101010 10101010
  x = 0xAAAAAAAA;
  printf("%d\n", any_odd_one(x));

  return 0;
}
