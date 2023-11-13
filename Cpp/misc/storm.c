/*
 * storm.c - A natual number N（N≠0）, if it's odd then 3N+1 else N/2.
 */

#include <stdio.h>

_Bool is_odd(int x)
{
    if (x % 2)
        return 1;
    return 0;
}

int main()
{
    /* code */
    int N;
    int cnt = 0;
    scanf("%d", &N);

    while (N > 1)
    {
        if (is_odd(N))
            N = 3 * N + 1;
        else
            N /= 2;
        cnt++;
    }

    printf("Storm count %d\n", cnt);
    return 0;
}
