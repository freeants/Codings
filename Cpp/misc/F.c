/*
* F.c
*/
#include <stdio.h>
#include <stdlib.h>

int n;       /* number of intger to be inputed */
int *arr;    /* array to hold all inputs */
int x, y, s; /* x, y -> min, max of arr[] */

void getInput()
{
    /* reads n from stdin */
    scanf("%u", &n);
    /* allocat mem for dynamic array */
    arr = (int *)malloc(n * sizeof(int));
    for (size_t i = 0; i < n; i++)
    {
        /* loop n times to read all inputs */
        scanf("%u", &arr[i]);
    }
}

void insertionSort(int arr[], int length)
{
    int i, j, tmp;
    for (i = 1; i < length; i++)
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

int findEvenSumUp(int arr[], int length)
{
    int Sum = 0;
    for (size_t i = 0; i < length; i++)
    {
        if ((arr[i] % 2) == 0)
            Sum = Sum + arr[i];
    }
    return Sum;
}

void work()
{
    /* get the array sorted, in increasing order */
    insertionSort(arr, n);
    /* min & max numbers are the begining and end of the sorted array */
    x = arr[0];
    y = arr[n - 1];
    /* find all even numbers and sum them up */
    s = findEvenSumUp(arr, n);
}

int main()
{
    /* get input from stdin */
    getInput();
    /* sort input array, find x, y and get s */
    work();
    /* output to stdout */
    printf("%d %d %d\n", x, y, s);

    return 0;
}