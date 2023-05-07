#include <stdio.h>
long long unsigned bd(int x);

int main()
{
    int k, n;
    scanf("%d", &k);
    while (k--)
    {
        scanf("%d", &n);
        printf("%11u\n", bd(n));
    }
    return 0;
}

long long unsigned bd(int x)
{
    if (x == 1 || x == 2)
    {
        return 1;
    }
    return bd(x - 1) + bd(x - 2);
}