/*
    File:       fib.c - caculates fibnacci serise of given n.
    Copyright:  © 2020-2025 freeants. All rights reserved.
 */
#include <stdio.h>

size_t fib(int n)
{
    int a = 0, b = 1, sum;
    for (size_t i = 0; i < n; i++)
    {
        sum = (a + b) % 1000000007;
        a = b;
        b = sum;
    }
    return a;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("fib(%d) = %zu\n", n, fib(n));
    return 0;
}
