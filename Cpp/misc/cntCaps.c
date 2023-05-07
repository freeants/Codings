/*
 *   File:       cntCaps.c - Count capital letters in a string input.
 */

#include <stdio.h>

#define LENGTH 100

int main(int argc, char const *argv[])
{
    char c, st[LENGTH];
    int cnt, i;

    printf("Enter a string : ");
    fgets(st, LENGTH, stdin);

    while ((c = st[i++]) != '\0')
    {
        /* Test if the character ASCII is within CAP rang */
        if (c > 64 && c < 91)
        {
            ++cnt; /* Increase counts */
        }
    }

    printf("Capital letter : %d\n", cnt);
    return 0;
}
