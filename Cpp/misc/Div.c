/*
 * Div.c - Keep dividing 1/3 * 3  and print console results
 * To demostrate that 0.999... = 1
 * (c) netants, 2016.
 **/

#include <stdio.h>

int main()
{
  int a = 1;
  int b = 3;

  unsigned long int i;

  printf("%d/%d * 3 = \n", a, b);

  for (i = 1; i < 2049; i++)
  {
    printf("%d", a / b * 3);
    a = (a % b) * 10;

    if (i > 4 && (i % 5 == 0))
      printf("\t");

    if (i % 50 == 0)
      printf("\n");
  }

  printf("\n");
  return 0;
}
