#include <iostream>
#include <thread> 
using namespace std; 

int main(int argc, char const *argv[])
{
    unsigned int c = thread::hardware_concurrency();
    cout <<"Hardware concurrency(CPU cores): " << c << endl;
    return 0;
}
