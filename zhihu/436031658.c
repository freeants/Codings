/*
    File:   436031658.c - C语言输入5个整数，存入数组中，找出与平均值最接近的元素及其下标？
    Copyright:  © 2020-2025 brave_brother. All rights reserved.
 */
#include <stdio.h>
#define ABS(x) ((x) > 0 ? (x) : -(x))
#define MAX 5

int index;

int searchNearest(int Arr[], int key)
{
    int value = ABS(key - Arr[0]);
    int num = 0;

    for (int i = 0; i < MAX; i++)
    {
        if (value > ABS(key - Arr[i]))
        {
            value = ABS(key - Arr[i]);
            num = Arr[i];
            index = i;
        }
    }
    return num;
}

int compAverage(int Arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += Arr[i];
    return sum / n;
}

int main()
{
    int A[MAX];
    printf("Input array item [%d]: ", MAX);
    for (int i = 0; i < MAX; i++)
        scanf("%d", &A[i]);

    int average, nearest;

    average = compAverage(A, MAX);
    nearest = searchNearest(A, average);

    printf("Average: %d, nearest: %d, index: A[%d]\n", average, nearest, index);
    return 0;
}