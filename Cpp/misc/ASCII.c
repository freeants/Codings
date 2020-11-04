/*
  ASCII.c
 */

#include <stdio.h>

int main()
{
  printf("\nPrintable ASCII codes (32 - 127):\n\n");

  for (int i = 32; i < 128; i++)
  {
    printf("%d\t%c\t ", i, i);
    if ((i - 31) % 5 == 0)
      printf("\n");
  }

  printf("\n");
  return 0;
}