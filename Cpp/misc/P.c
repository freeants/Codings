/*
 * P.c
 */

#include <stdio.h>

double P(unsigned int n, double x)
{
    if (n == 0) return 1;
    if (n == 1) return x;
    return ((2 * n - 1) * P(n - 1, x) - (n - 1) * P(n - 2, x)) / n;
}

int main()
{
    double x;
    unsigned int n;

    scanf("%u%lf", &n, &x);
    printf("%.2f\n", P(n, x));

    return 0;
}