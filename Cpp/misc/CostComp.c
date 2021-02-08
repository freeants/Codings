/*
 * CostComp.c
 */

#include <stdio.h>

int main()
{
  double c1, c2, c3; /* cost for each */
  double d, t;       /* distance & time */

  float speed = 1; /* 1km per minute */

  printf("\nDist.\tYiChe \tDidi \tUber\n");

  for (d = 1; d < 50; d++)
  {
    t = d / speed;
    c1 = (2 * d + 0.4 * t) * 0.5;
    c2 = 1.3 * d + 0.3 * t - 10;
    c3 = 1.7 * d + 0.35 * t - 15;

    if (c1 > 0 && c2 > 0 && c3 > 0)
    {
      printf("%.0f\t%.1f\t%.1f\t%.1f\n", d, c1, c2, c3);
    }

    //      if ( c1 >0 && c2 >0 && c3 >0)
    //	{.
    //  if (c1 >= c2)
    //    {
    //      printf("Yidao starts higher than Didi ->\n");
    //      printf("Distance = %f; Time = %f; Cost = %f.\n", d,t,c1);
    //      break;
    //    }
    //  else if (c2 >= c3)
    //    {
    //      printf("Didi starts higher than Uber =>\n");
    //      printf("Distance = %f; time = %f; cost = %f\n", d,t,c3);
    //      break;
    //    }
    //}
  }
  return 0;
}
