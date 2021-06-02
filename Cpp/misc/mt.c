/*
    File:   mt.c - print the multiply table.
    Author: freeants, All rights reserved.
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* code */
    int x, y, z;
    for (int x = 0; x < 10; x++)
    {
        for (int y = 1; y <= x; y++)
        {
            z = x * y;
            printf("%d*%d=%d ", y, x, z);
        }
        printf("\n");
    }
    return 0;
}
