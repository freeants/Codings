/*
 6174.c - The math blackhole.
*/

#include <stdio.h>

int tran(int m)
{
    int a[4], i, j, t;
    a[0] = m % 10;
    a[1] = m / 10 % 10;
    a[2] = m / 100 % 10;
    a[3] = m / 1000;

    // Sorting
    for (i = 0; i < 4; i++)
        for (j = i + 1; j < 4; j++)
            if (a[i] < a[j])
            {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }

    i = a[3] * 1000 + a[2] * 100 + a[1] * 10 + a[0]; // Min
    j = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3]; // Max

    printf("%d - %4d = %d\n", j, i, j - i);
    return (j - i);
}
int main(void)
{
    int x, count;

    scanf("%d", &x);
    count = 1;

    while (x != 6174) // count to 6147
    {
        printf("%d. ", count++);
        x = tran(x);
        // count++;
    }

    printf("Total %d counts.\n", count);

    return 0;
}
