#include <stdio.h>

int main()
{
    int a = 3, b = 4, c;
    c = a++ > 2 || b-- >= 4;
    printf("%d\n", b);
    return 0;
}