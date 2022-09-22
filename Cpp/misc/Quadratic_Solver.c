/*
 * File: Quadratic_Solver.c - Caculate the roots of ax² + bx + c = 0
 */

#include <stdio.h>
#include <math.h>

int main()
{
  float coe[3], x1, x2, delta;

  /* prompt for input a, b & c */
  // printf("Calculate the roots of ax² + bx + c = 0, input a, b and c: ");

  for (int i = 0; i < 3; i++)
    scanf("%f", &coe[i]);

  if (coe[0] == 0)
  {
    /* FALSE */
    printf("FALSE\n");
    return -1;
  }

  /* delta = b² - 4ac */
  delta = coe[1] * coe[1] - 4.0 * coe[0] * coe[2];
  printf("Inputs appear to be: %.2fx² + %.2fx + %.2f = 0\n",
         coe[0], coe[1], coe[2]);
  printf("delta = b² - 4ac = %.2f\n", delta);

  /* determin value of delta */
  if (delta > 0)
  {
    x1 = (-coe[1] + sqrt(delta)) / 2.0 * coe[0];
    x2 = (-coe[1] - sqrt(delta)) / 2.0 * coe[0];
    printf("∆ = %.2f > 0\n", delta);
    printf("x1 = %.2f; x2 = %.2f\n", x1, x2);
  }
  else if (delta == 0)
  {
    x1 = x2 = -coe[1] / 2.0 * coe[0];
    printf("∆ = %.2f = 0\n", delta);
    printf("x1 = x2 = %.2f\n", x1);
  }
  else /* delta < 0, has two complex number roots */
  {
    /* m + n * i format */
    float m, n;
    m = -coe[1] / 2.0 * coe[0];
    n = sqrt(-delta) / 2.0 * coe[0];
    printf("∆ = %.2f < 0\n", delta);
    printf("x1 = %.2f + %.2fi; x2 = %.2f - %.2fi\n", m, n, m, n);
  }

  return 0;
}