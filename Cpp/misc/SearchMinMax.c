/*
    File    :  SearchMinMax.c 
    Purpose :  Search with array to find the max & min value give it's original
               index.
    Author  :  freeants (c), All rights reserved.
    Version :  v0.1 Nov 11, 2021. 
*/

#include <stdio.h>
#include <stdlib.h> /* for srand() */
#include <time.h>   /* for time() */

int N = 20, X = -100, Y = 200; /* Number of randoms; range for random numbers [x, y] */
int *a, *b;                    /* Arrays of orignial and sorted */
int max, min, i_max, i_min;    /* max and min value and their index */

/*
 * The Insertion Sort method.
 */
void insertionSort(int *arr, int n)
{
    int i, j, tmp;
    for (i = 1; i < n; i++)
    {
        j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }
    }
}

/*
 * The Sequence Search method.
 */
int SequenceSearch(int *arr, int n, int T)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == T)
            return i;
    return -1;
}

/*
 * Generate random number in rang [x, y]
 */
int GenRndNum(int x, int y)
{
    /* rand() % (max_number + 1 - minimum_number) + minimum_number */
    return (rand() % (y + 1 - x) + (x));
}

/*
 * Build n randoms in [x, y]
 */
void BuildRandoms(int n, int x, int y)
{
    /* Define and allocate memory for dynamic array */
    a = (int *)malloc(n * sizeof(int));
    b = (int *)malloc(n * sizeof(int));

    /* Use current time as random seed */
    srand(time(0));
    for (size_t i = 0; i < n; i++)
    {
        /* Assign n randoms to array */
        a[i] = GenRndNum(x, y);
        b[i] = a[i];
    }
}

/*
 * Print the sorted array of randoms
 */
void printArray(int *arr, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    /* Build N numbers of randoms in [X, Y] */
    BuildRandoms(N, X, Y);

    /* Sort the randoms in ascending order */
    insertionSort(a, N);
    min = a[0];
    max = a[N - 1];

    /* Search for max and min orignal index in b */
    i_max = SequenceSearch(b, N, max);
    i_min = SequenceSearch(b, N, min);
    printf("Array of %d numbers: ", N);
    printArray(b, N);
    printf(" Max and min values: %d, %d\n  Oringinal indexes: %d, %d\n ", max, min, i_max, i_min);

    /* free array */
    free(a);
    free(b);

    return 0;
}