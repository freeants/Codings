#include <stdio.h>
#define PI 3.14159

int main()
{
    double x, k, s = 0;
    int n;
    scanf("%lf%d", &x, &n);
    k = x = x * PI / 180;
    for (size_t i = 1; i <= n; i++)
    {
        s += k;
        k *= -x * x / (i * 2 * (i * 2 + 1));
    }
    printf("%.4f\n", s);
    return 0;
}