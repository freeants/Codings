/*
    File    :   1005.c 
    Problem :   I Think I need a Houseboat
    Author  :   freeants (c), All rights reserved.
    Version :   v0.1 Nov 28, 2021. 
*/

#include <stdio.h>
#include <stdlib.h> /* for malloc() */
#include <math.h>   /* for sqrtf() */

#define PI 3.1415926

int N;          /* define data sets N */
float X, Y;     /* each coordinates (X, Y) */
float **coords; /* a 2D (N-row, 2-col) float arry for holding all input (X,Y) */

/*
 *  Get N and each (X, Y) and save into 2D array
 */
void GetInput()
{
    /* get N */
    scanf("%d", &N);

    /* Define and allocat memory for dynamic array */
    coords = (float **)malloc(N * sizeof(float *));
    for (int i = 0; i < N; ++i)
    {
        coords[i] = (float *)malloc(2 * sizeof(float));
    }

    /* get inputs from each line */
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 2; j++)
        {
            scanf("%f", &coords[i][j]);
        }
}

/*
 *  Get the area of semicircle
 */
float SemiArea(float r)
{
    return PI * r * r / 2.0;
}

/*
 *  Get the area of eroding by year - 50 square miles each year
 */
float ErodArea(int year)
{
    return year * 50.0;
}

/*
 *  Do tests and print results
 */
void Test()
{
    float radius;

    for (int i = 0; i < N; i++)
    {
        int year = 1;
        X = coords[i][0];
        Y = coords[i][1];
        radius = sqrtf(X * X + Y * Y);

        /* compare areas */
        while (ErodArea(year) <= SemiArea(radius))
        {
            /* code */
            year++;
        }
        printf("Property %d: This property will begin eroding in year %d.\n", i + 1, year);
    }
    printf("END OF OUTPUT.\n");
}

/*
 * Free memory of the 2-D array
 */
void FreeMem()
{
    for (int i = 0; i < N; ++i)
    {
        free(coords[i]);
    }
    free(coords);
}

int main()
{
    /* get N and (X, Y) */
    GetInput();

    /* do tests */
    Test();

    /* free memory */
    FreeMem();

    return 0;
}
