/*
    File:       factorial.cxx - caculates n! the GMP way.
    Copyright:  © 2020-2025 freeants(ffu@alumni.sjtu.edu.cn). All rights reserved.
 */

#include <iostream>
#include <gmpxx.h>

class Factorial
{
    int n;          // n that needs to find its factorial
    mpz_class fact; // the result of n!
public:
    Factorial();        // Constructor
    void compFact(int); // do compute
};

Factorial::Factorial()
{
    fact = 1;
}

void Factorial::compFact(int n)
{
    for (int i = 2; i <= n; ++i)
        fact *= i;
    std::cout << fact.get_str(10) << "\n";
    // fact.
}
int main(int argc, char **argv)
{
    /** Check cmd line args */
    if (argc != 2)
    {
        printf("Usage: fact n\t//n is the integer for n!\n");
        return 1;
    }
    int n;
    n = atoi(argv[1]);

    try
    {
        /* Instantiation */
        Factorial objMain;
        /* Caculation */
        objMain.compFact(n);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }

    return 0;
}