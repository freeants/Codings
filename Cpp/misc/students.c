/*
    File    :   students.c 
    Purpose :   A school recruits 3000 students in year 2006, plans to increase 3% annually.
                In which year the amount will reach 5000? 
    Author  :   freeants (c), All rights reserved.
    Version :   v0.1 Nov 9, 2021. 
*/

#include <stdio.h>

#define INIT_YRE 2006 /* Initial year */
#define INIT_NUM 3000 /* Initial number */
#define INCR_RAT 0.03 /* Incremental rate */
#define TARG_NUM 5000 /* Target number */

int main(int argc, char const *argv[])
{
    int yrs, num = INIT_NUM;
    /* Loop through each year and check if meet target number */
    for (yrs = INIT_YRE + 1; num < TARG_NUM; ++yrs)
    {
        /* Get the incremented number */
        num *= (1 + INCR_RAT);
        printf("Year: %d, Number: %d\n", yrs, num);
    }

    return 0;
}
