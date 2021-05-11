/*
    isAbsltPrime.cc - test if the input integer is Absolute Prime number.
    Definition:
        A prime number is called an absolute prime if every permutation of its
        digits in base 10 is also a prime number. 
        For example: 2, 3, 5, 7, 11, 13 (31), 17 (71), 37 (73) 79 (97), 
        113 (131, 311), 199 (919, 991) and 337 (373, 733) are absolute primes.
    Author: freeants, All rights reserved.
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

static int digits_no[] = {0, 2, 4, 5, 6, 8};
int cnt = 0;

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
 * Check if x is prime number
 */
bool isPrime(int x)
{
    if (x <= 1)
        return false;

    for (int i = 2; i < x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

// Iterative function to find permutations of a string
void permutations(string s, int n)
{
    // sort the string in a natural order
    sort(s.begin(), s.end());

    while (isPrime(strtol(s, NULL, 10)))
    {
        // print the current permutation
        cout << s << " ";

        /* The following code will rearrange the string to the next lexicographically
           ordered permutation (if any) or return if we are already at the
           highest possible permutation */

        // Find the largest index `i` such that `s[i-1]` is less than `s[i]`
        int i = n - 1;
        while (s[i - 1] >= s[i])
        {
            // if `i` is the first index of the string, we are already at the last
            // possible permutation (string is sorted in reverse order)
            if (--i == 0)
            {
                return;
            }
        }

        // find the highest index `j` to the right of index `i` such that
        // `s[j] > s[i-1]` (`s[i…n-1]` is sorted in reverse order)

        int j = n - 1;
        while (j > i && s[j] <= s[i - 1])
        {
            j--;
        }

        // swap character at index `i-1` with index `j`
        swap(s[i - 1], s[j]);

        // reverse substring `s[i…n-1]`
        reverse(s.begin() + i, s.end());
    }
}

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 1000; i++)
    {
        if (isNoBannedDigits(digits_no, i))
        {
            if (isPrime(i))
            {
                /** convert i into string for permutes tests */
                int len = snprintf(NULL, 0, "%d", i);
                string str;
                snprintf(str, len + 1, "%d", i);

                permutations(str, len);

                delete str;
            }
        }
    }

    // printf("\nTotal %d absolute primes found.\n", cnt);
    return 0;
}
