/**
 * 1-6.c - Verify that the expression getchar()!=EOF is 0 or 1.
 **/
#include <stdio.h>

int main()
{
    int c;

    while (c = getchar() != EOF)
        printf("%d\n", c);
    printf("%d - at EOF\n", c);

    return 0;
}