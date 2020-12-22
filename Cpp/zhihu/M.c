/*
 * M.c - Input an integer M, judge if it's odd/even and 
 * positive/negative.
 */

#include <stdio.h>

_Bool isOdd(int x)
{
    if (x % 2)
        return 1;
    return 0;
}

_Bool isPositive(int x)
{
    if (x > 0)
        return 1;
    return 0;
}

int main()
{
    int M;
    scanf("%d", &M);
    if (isOdd(M))
        printf("It's odd ");
    else
        printf("it's even ");
    if (isPositive(M))
        printf("and positive.\n");
    else
        printf("and negative.\n");
    return 0;
}