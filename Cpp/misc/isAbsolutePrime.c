/*
    isAbsolutePrime.c - test if the input integer is Absolute Prime number.
    Definition:
        A prime number is called an absolute prime if every permutation of its
        digits in base 10 is also a prime number. 
        For example: 2, 3, 5, 7, 11, 13 (31), 17 (71), 37 (73) 79 (97), 
        113 (131, 311), 199 (919, 991) and 337 (373, 733) are absolute primes.
    Author: freeants, All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // for bool type in C

static int digits_no[] = {0, 2, 4, 5, 6, 8};
int *Permutes; // save all permutations of a prime number

/*
 * Checks if digit d is present in number x.
 */
bool isDigitPresent(int d, int x)
{
    while (x > 0)
    {
        if (x % 10 == d)
            break;
        x = x / 10;
    }
    return (x > 0);
}

/*
 * Check if there's no banned digits
 * D[] contains banned digits.
 */
bool isNoBannedDigits(int *D, int x)
{
    bool noBanned = false;
    /** get the length of the array */
    int len = sizeof(digits_no) / sizeof(digits_no[0]);
    for (int i = 0; i < len; i++)
    {
        if (isDigitPresent(D[i], x))
        {
            noBanned = false;
            return noBanned;
        }
        else
            noBanned = true;
    }
    return noBanned;
}

/*
 * Check if items in x[] are prime numbers
 */
bool isPrime(int x)
{
    //int len;
    //len = sizeof(Permutes) / sizeof(Permutes[0]);
    //for (int i = 0; i < len; i++)
    //{
        if (x <= 1)
            return false;
        for (int i = 2; i < x; i++)
        {
            if (x % i == 0)
                return false;
        }
    //}
    return true;
}

/*
 *  To swap values at two pointers
 */
void swap(char *x, char *y)
{
    char tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

/*
 * To generate permutations of string
 *  This function takes three parameters:
 *   1. String
 *   2. Starting index of the string
 *   3. Ending index of the string.
 *  And save all permutations into array.
 */
void enmuePermutes(char *a, int l, int r)
{
    int i;
    if (l == r)
    {
        /** Define and allocate memory for dynamic array to stroe all permutes */
        //Permutes = malloc(r * sizeof(int));
        // Problematic on value assign
        //Permutes[i] = atoi(a);
        //printf("chk 2: Permutes[%d]= %d\n", r, Permutes[i]);
        if (isPrime(atoi(a)))
        {
            printf("%s ", a);
        }
        
    }
    else
    {
        for (i = l; i <= r; i++)
        {
            swap((a + l), (a + i));
            enmuePermutes(a, l + 1, r);
            swap((a + l), (a + i)); //backtrack
        }
    }
}

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 1000; i++)
    {
        if (isNoBannedDigits(digits_no, i))
        {
            /** convert i into string for permutes tests */
            int len = snprintf(NULL, 0, "%d", i);
            char *str = malloc(len + 1);
            snprintf(str, len + 1, "%d", i);
            //printf("chk 1:%d\n", i);
            /** Get all permutes and save to gloable array */
            enmuePermutes(str, 0, len - 1);

            //if (isPrimeArray(Permutes))
            //{
            //    printf("%d ", i);
            //}
            free(str);
        }
    }

    free(Permutes);
    return 0;
}
