/*
    File    :   1006.c 
    Problem :   Biorhythms
    Author  :   freeants (c), All rights reserved.
    Version :   v0.1 Nov 28, 2021. 
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int p, e, i, d;
    int time = 1;
    while (scanf("%d%d%d%d", &p, &e, &i, &d) != EOF)
    {
        /* test end input */
        if (p == -1 && e == -1 && i == -1 && d == -1)
            break;

        int n = (5544 * p + 14421 * e + 1288 * i - d + 21252) % 21252;
        if (n == 0)
            n = 21252;
        printf("Case %d: the next triple peak occurs in %d days.\n", time++, n);
    }
    return 0;
}
