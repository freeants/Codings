#include <stdio.h>

int main()
{
    int n = 10; // assuming 16 bit int
    for (int i = 15; i >= 0; i--)
        printf("%d", ((n >> i) & 1));
    printf("\n");
    return 0;
}
