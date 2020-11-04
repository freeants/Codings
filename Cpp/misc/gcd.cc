// gcd.cc

#include <iostream>
using namespace std;

static int gcd(int p, int q)
{
    if (q == 0)
        return p;
    int r = p % q;
    return gcd(q, r);
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        cout << "usage: gcd p q" << endl;
        return 1;
    }

    int p = stoi(argv[1]);
    int q = stoi(argv[2]);
    cout << "gcd(" << p << ", " << q << ") = " << gcd(p, q) << endl;
    return 0;
}