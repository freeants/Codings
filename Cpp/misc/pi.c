/*
 * pi.c - compute PI to c digits
 **/
#include <stdio.h>
int main()
{
  int a = 10000, b, c = 35000, d, e, f[35001], g;
  for (; b - c;)
    f[b++] = a / 5;
  for (; d = 0, g = c * 2; c -= 14, printf("%.4d", e + d / a), e = d % a)
    for (b = c; d += f[b] * a, f[b] = d % --g, d /= g--, --b; d *= b);
}
