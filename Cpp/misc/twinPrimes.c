/*
    File    :   twinPrimes.c
    Purpuse :   Print twin primes to the given limit.
    Author  :   freeants (c), All rights reserved.
    Version :   v0.1. Nov 28, 2021
*/

#include <stdio.h>
#include <stdbool.h> // for bool type in C

/*
 * Check if x is prime number
 */
bool isPrime(int x)
{
    if (x <= 1)
        return false;

    for (int i = 2; i < x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main()
{
    /* the given range */
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        /* test if they are twin primes */
        if (isPrime(i) && isPrime(i + 2))
        {
            /* print twin primes */
            printf("%d %d\n", i, i + 2);
        }
    }
    return 0;
}
