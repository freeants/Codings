/* va.c - Test the value of a in formula.
 *
 */

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 4;
    printf("%d", (a - 1) * (++a));
    return 0;
}
