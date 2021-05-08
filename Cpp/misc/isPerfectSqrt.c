/*
    isPerfectSqrt.c - test if the input integer has a perfect sqare root.
    Author: freeants, All rights reserved.
*/

#include <stdio.h>
#include <stdbool.h> // for bool type in C

int root;
/*
 * Do Binary Search for floor(sqrt(x)) and testing if it has perfect square root.
 */
bool isPerfectSqrt(int x)
{
    /** Base case check */
    if (x == 0 || x == 1)
        return true;

    int start = 1, end = x, ans;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        /** If x is perfect square number */
        if (mid * mid == x)
        {
            root = mid;
            return true;
        }

        /** Keep searching */
        if (mid * mid < x)
        {
            start = mid + 1;
            ans = mid;
        }
        else
            end = mid - 1;
    }

    root = ans;
    return false;
}

int main(int argc, char const *argv[])
{
    int x;
    printf("Input an integer: ");
    scanf("%d", &x);

    if (isPerfectSqrt(x))
    {
        printf("%d has perfect square root %d.\n", x, root);
    }
    else
    {
        printf("%d has no perfect square root.\nIts integer square root is %d.\n", x, root);
    }

    return 0;
}
