/*
 * SameBirth.cpp - Give the possibility of two who born the same day
 *                 in N people.
 * Author: freeants, rights reserved.
 */

#include <gmpxx.h>
#include <bits/stdc++.h>
using namespace std;

// Calculate n! using GMP lib.
mpz_class fact(int n)
{
    mpz_class fact = 1;
    for (size_t i = 2; i <= n; ++i)
        fact *= i;
    // cout << "fact(" << n << ") = " << fact
    //      << "\n";
    return fact;
}

// Pn = 1 - fact(365) / (365**n * fact(365-n))
mpf_t Pn(int n)
{
    mpz_class power;
    mpz_ui_pow_ui(power.get_mpz_t(), 365, n);
    cout << "pow = " << power << "\n";
    return fact(365) / (power * fact(365 - n));
}

int main(int argc, char const *argv[])
{
    int N;

    cin >> N;
    cout << Pn(N).get_str(10) << "\n";
    return 0;
}
