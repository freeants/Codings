/*
    File    :   Swaptst.cc - In demostrating and comparision of various swap methods.
    Author  :   freeants (c), All rights reserved.
    Version :   v1.0 Feb 25, 2021. 
*/
#include <iostream>
#include <chrono>
#include <random>
using namespace std;

/*
 * Gloabl vars
 */
const int max_size = 99999999; // Size of data dictionary
int *a;                        // Data set array
int tmp;                       // tmp
string info[] = {"0. Using 'tmp' method",
                 "1. bitwise XOR method",
                 "2. inline asm method",
                 "3. inline 'xchg' method",
                 "4. std::swap() method"};

/* Swap(int *, int *, int)
 * Swap the value of two elements.
 */
void Swap(int *a, int *b, int mode)
{
    switch (mode)
    {
    case 0:
        /* Swap using a third variable tmp, traditional swapping method */
        tmp = *a;
        *b = *a;
        *a = tmp;
        break;
    case 1:
        /* Swap using bitwise XOR, sequence point introduced using comma */
        (*a ^= *b), (*b ^= *a), (*a ^= *b);
        break;
    case 2:
        /* Inline GNU C asm for optimal performance, portable to all platform */
        asm(""
            : "=r"(*a), "=r"(*b)
            : "1"(*a), "0"(*b));
        break;
    case 3:
        /* Inline x86 'xchg' asm , no portability outside X86 */
        asm("xchg %0, %1;"
            : "+r"(*a), "+r"(*b));
        break;
    case 4:
        /* System lib std::swap() */
        swap(*a, *b);
        break;
    }
}

/*
 * Build data set and count timing.
 */
void BuildDataSet()
{
    cout << "Building data dictionary ... (size: " << max_size << ") - ";

    /* Define the data array */
    a = new int[max_size];

    random_device rd;                              //obtain a random number from hardware
    mt19937 gen(rd());                             //seed the generator
    uniform_int_distribution<> distr(0, max_size); //define the range

    /* Assign values to array */
    auto t0 = chrono::high_resolution_clock::now(); //get start time
    for (int i = 0; i < max_size; i++)
        a[i] = distr(gen);
    auto t1 = chrono::high_resolution_clock::now(); //get end time

    cout << chrono::duration_cast<chrono::microseconds>(t1 - t0).count() << " micro(μ) seconds" << endl;
}

/*
 * Display tests info - Lambda expression way.
 */
static auto dispResult = [](string str, auto diffTime) {
    cout << str << '\t' << chrono::duration_cast<chrono::microseconds>(diffTime).count() << " ms." << endl;
};

/*
 * Start the test process
 */
void test()
{
    for (int m = 0; m < 5; m++)
    {
        auto t0 = chrono::high_resolution_clock::now(); //get start time
        for (size_t i = 1; i < max_size; i++)
        {
            Swap(&a[i], &a[i - 1], m); // test 5 swap methods
        }
        auto t1 = chrono::high_resolution_clock::now(); //get end time
        dispResult(info[m], t1 - t0);
    }
}

int main()
{
    try
    {
        BuildDataSet(); // Build the dataset
        test();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    delete[] a;
    return 0;
}