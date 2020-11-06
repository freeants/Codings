/* Chud_Pi.cxx
   Computing pi by Binary Splitting Algorithm with GMP libarary.
   clang++ -o chud_pi Chud_Pi.cxx -lgmpxx -lgmp -std=c++17 -O3
*/

#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <iomanip>
#include <gmpxx.h>

using namespace std;

const string MSG_USAGE = "Usage:\nchud_pi n <file>\n\nwhere <file> is one of:\n\t- A legal file name for saving pi value or\n\t- BLANK, will just compute without saving.\n\nThe n is an integer number specifying the pi digits to compute\n\nExample:\nchud_pi 1024 Pi.txt\n";

char *FILENAME;
unsigned int DIGITS;

struct PQT
{
    mpz_class P, Q, T;
};

class Chudnovsky
{
    // Declaration
    mpz_class A, B, C, D, E, C3_24; // GMP Integer
    int PREC, N;                    // Integer
    double DIGITS_PER_TERM;         // Long
    PQT compPQT(int n1, int n2);    // Computer PQT (by BSA)

public:
    Chudnovsky();  // Constructor
    void compPi(); // Compute PI
};

/*
 * Constructor
 */
Chudnovsky::Chudnovsky()
{
    // Constants
    A = 13591409;
    B = 545140134;
    C = 640320;
    D = 426880;
    E = 10005;
    DIGITS_PER_TERM = 14.1816474627254776555; // = log(53360^3) / log(10)
    C3_24 = C * C * C / 24;
    N = DIGITS / DIGITS_PER_TERM;
    PREC = DIGITS * log2(10);
}

/*
 * Compute PQT (by Binary Splitting Algorithm)
 */
PQT Chudnovsky::compPQT(int n1, int n2)
{
    int m;
    PQT res;

    if (n1 + 1 == n2)
    {
        res.P = (2 * n2 - 1);
        res.P *= (6 * n2 - 1);
        res.P *= (6 * n2 - 5);
        res.Q = C3_24 * n2 * n2 * n2;
        res.T = (A + B * n2) * res.P;
        if ((n2 & 1) == 1)
            res.T = -res.T;
    }
    else
    {
        m = (n1 + n2) / 2;
        PQT res1 = compPQT(n1, m);
        PQT res2 = compPQT(m, n2);
        res.P = res1.P * res2.P;
        res.Q = res1.Q * res2.Q;
        res.T = res1.T * res2.Q + res1.P * res2.T;
    }

    return res;
}

/*
 * Compute PI
 */
void Chudnovsky::compPi()
{
    cout << "**** PI Computation ( " << DIGITS << " digits )" << endl;

    // Time (start)
    auto t0 = chrono::high_resolution_clock::now(); //get start time

    // Compute Pi
    PQT PQT = compPQT(0, N);
    mpf_class pi(0, PREC);
    pi = D * sqrt((mpf_class)E) * PQT.Q;
    pi /= (A * PQT.Q + PQT.T);

    // Time (end of computation)
    auto t1 = chrono::high_resolution_clock::now(); //get current time
    cout << "TIME (COMPUTE): "
         << (double)chrono::duration_cast<chrono::microseconds>(t1 - t0).count() / 1000000
         << " seconds." << endl;

    // Output
    if (FILENAME != NULL)
    {
        ofstream ofs(FILENAME);
        ofs.precision(DIGITS + 1);
        ofs << pi << endl;

        // Time (end of writing)
        auto t2 = chrono::high_resolution_clock::now(); //get current time

        // Get file size
        ifstream in(FILENAME, ios::binary | ios::ate);

        cout << "TIME (WRITE)  : "
             << (double)chrono::duration_cast<chrono::microseconds>(t2 - t1).count() / 1000000
             << " seconds." << endl
             << "FILE SAVED    : " << FILENAME
             << " ( " << in.tellg() << " BYTES )" << endl;
    }
}

int main(int argc, char **argv)
{
    // Check cmd line args
    if (argc <= 1 || argc > 3)
    {
        cerr << MSG_USAGE;
        return 1;
    }
    cout << "Compute pi(π) by Binary Splitting Algorithm with GMP libarary."
         << endl;

    DIGITS = stoi(argv[1]);
    FILENAME = argv[2];

    try
    {
        // Instantiation
        Chudnovsky objMain;

        // Compute PI
        objMain.compPi();
    }
    catch (...)
    {
        cout << "ERROR!" << endl;
        return -1;
    }

    return 0;
}