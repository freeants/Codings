/*
    permute.c - print the permuations of a given string.
    Author: freeants, All rights reserved.
*/

#include <stdio.h>
#include <string.h>

//function to swap two variables
void swap(char *a, char *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void permute(char *a, int l, int r)
{
    int i;
    if (l == r)
        printf("%s\n", a);
    else
    {
        for (i = l; i <= r; i++)
        {
            swap((a + l), (a + i));
            permute(a, l + 1, r);
            swap((a + l), (a + i));
        }
    }
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("Usage: permute xxxx\n");
        return -1;
    }

    int n = strlen(argv[1]);
    permute(argv[1], 0, n - 1);
    return 0;
}