/*
 * swcInput.c - Switch Caps/Lower inputs, output ASCII if not letter.
 */

#include <stdio.h>

#define LENGTH 100

int main(int argc, char const *argv[])
{
    char c, st[LENGTH];
    int i = 0;

    puts("Enter a string : ");
    fgets(st, LENGTH, stdin);

    while ((c = st[i++]) != '\0')
    {
        /* Test if the character ASCII in CAPS/Lower range */
        if (c > 64 && c < 91)
        {
            c += 32; /* Convert to lower letter */
            putchar(c);
        }
        else if (c > 96 && c < 123)
        {
            c -= 32; /* Convert to capital letter */
            putchar(c);
        }
        else
            printf("[%d]", c);
    }

    printf("\n");
    return 0;
}