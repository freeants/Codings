/*
    File:       factorial.c - caculates n! the recursive way.
    Copyright:  © 2020-2025 freeants. All rights reserved.
 */

extern int printf(const char *format, ...);
extern int atoi(const char *str);

unsigned long fact_recursive(int n)
{
    if (n == 0)
        return 1;
    return fact_recursive(n - 1) * n;
}

unsigned long fact_iterative(int n)
{
    unsigned long fact = 1;
    for (int i = 2; i <= n; i++)
        fact *= i;
    return fact;
}

int main(int argc, char **argv)
{
    /** Check cmd line args */
    if (argc != 2)
    {
        printf("Usage: fact n\t//n is the integer for n!\n");
        return 1;
    }
    int n;
    n = atoi(argv[1]);
    printf("%d! = %lu, %lu \n", n, fact_recursive(n), fact_iterative(n));
    return 0;
}