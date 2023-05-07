#include <stdio.h>

void swap(int* a, int* b)
{
    if(a != b)
    {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
}

void func(int* array, int array_size, int index, int* count)
{
    if(index == array_size)
    {
        if(array[0] && array[1] && array[3] && array[6])
        {
            if(
                array[0] + 
                (array[1] * 10 + array[2]) + 
                (array[3] * 100 + array[4] * 10 + array[5]) ==
                (array[6] * 1000 + array[7] * 100 + array[8] * 10 + array[9])
            )
            {
                printf(
                    "%d\t%d + %d + %d = %d\n",
                    *count + 1,
                    array[0],
                    array[1] * 10 + array[2],
                    array[3] * 100 + array[4] * 10 + array[5],
                    array[6] * 1000 + array[7] * 100 + array[8] * 10 + array[9]
                );
                (*count)++;
            }
            
        }   
    }
    else
        for(int i = index; i < array_size; i++)
        {
            swap(array + i, array + index);
            func(array, array_size, index + 1, count);
            swap(array + i, array + index);
        }
}

int main()
{
    int test[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int count = 0;
    func(test, 10, 0, &count);
    printf("count = %d", count);
    return 0;
}