// sf.cc - Search prime factor of a given integer

#include <iostream>
using namespace std;

void sf(int number, int factor = 2)
{
    if (number < 2)
        return;
    if (number % factor == 0)
    {
        sf(number / factor, factor);
        cout << factor << " ";
    }
    else
        sf(number, factor + 1);
}

int main(int argc, char **argv)
{
    // Check cmd line args
    if (argc != 2)
    {
        cerr << "Usage: sf n" << endl;
        return 1;
    }
    sf(stoi(argv[1]));
    cout << "\n";

    return 0;
}