/*
 * Return 1 when x can be represented as an n-bit, 2’s complement
 * number; 0 otherwise
 * Assume 1 <= n <= w
 * 这个还不懂，参考：http://stackoverflow.com/questions/14792521/bitwise-operations-and-shifts
 */
int fits_bits(int x, int n) {
  int w = sizeof(int) << 3;
  // -n = ~n + 1
  int shift = w + (~n + 1);
  // 填充符号位
  return !(x ^ (x << shift >> shift));
}

int main(void)
{
  printf("%d\n", fits_bits(5, 3));
  printf("%d\n", fits_bits(-4, 3));
  return 0;
}
