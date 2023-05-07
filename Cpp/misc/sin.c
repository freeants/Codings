/*
    File:       sin.c - calculates sin(x) by Maclaurin's series.
    Copyright:  © 2020-2025 freeants. All rights reserved.
 */
#include <stdio.h>
#define ABS(x) ((x) > 0 ? (x) : -(x))

/*
 * Calculates n!
 */
unsigned long factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}
/*
 * Calculates x^n
 */
double power(double x, int n)
{
    if (n == 0)
        return 1;
    return x * power(x, n - 1);
}
/*
 * Calculates sin(x,n)
 */
double sine(double x, int n)
{
    double sum;
    if (n == 1)
        return x;
    sum = power(-1, n - 1) * (power(x, 2 * n - 1) / factorial(2 * n - 1));
    return sum + sine(x, n - 1);
}

int main()
{
    double x;
    int n;
    /* Input x and n */
    scanf("%lf%n", &x, &n);
    /* Output sin(x) */
    printf("%.4lf\n", sine(x * 3.14159 / 180, n));
    return 0;
}
