/*
    palindrome.cpp - finds palindrome numbers in given range.
    Author: freeants, All rights reserved.
*/

#include <iostream>
using namespace std;

int cnt = 0;    // total numbers of palindrome numbers

/*
 * check if the number is a palindrom or not.
 */
bool isPalindrome(int n)
{
    // get reverse of the number
    int reverse = 0;

    for (size_t i = n; i > 0; i /= 10)
        reverse = reverse * 10 + i % 10;

    return (n == reverse);
}

/*
 * count and print palindrome numbers
 */
void Palindromes(int min, int max)
{
    for (size_t i = min; i <= max; i++)
        /* print the count */
        if (isPalindrome(i))
        {
            cout << i << " ";
            cnt++;
        }
}

int main()
{
    cout << "Finding palindrome numbers in [0, 999999] ..." << endl;
    try
    {
        Palindromes(10, 999999);
        cout << endl
             << "Total: " << cnt << " numbers found." << endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
