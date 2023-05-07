//: Dec2Bin.cc - Convert integer to binary formats

#include <iostream>
#include <limits>
#include <bitset>
using namespace std;

int main()
{
  int n;

  cout << "Enter an integer in decimal: ( 0 to quit ) ";
  // Looping for contiuns converting
  while (true)
  {
    cout << endl
         << "--> ";
    cin >> n;
    // Validating inputs and asking for numbers
    while (cin.fail())
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Bad entry. Enter a NUMBER: ";
      cin >> n;
    }

    if (n == 0)
      break; // quit loop
    cout << "Octal: " << oct << n;
    cout << ", Hexdecimal: " << hex << n;
    cout << ", Binary: " << bitset<16>(n) << endl;
  }
  return 0;
}
