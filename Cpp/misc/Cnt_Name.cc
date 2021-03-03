#include <iostream>
#include <iomanip>
using namespace std;

/* define the first & last name structure */
typedef struct
{
    string firstName, lastName;
    int first_len, last_len;
} Name;

int main()
{
    Name n;
    /* Ask for name input */
    cout << "First name: ";
    cin >> n.firstName;
    cout << "Last name : ";
    cin >> n.lastName;

    /* Print the inputed name */
    cout << n.firstName << " " << n.lastName << endl;
    n.first_len = n.firstName.length();
    n.last_len = n.lastName.length();

    /* Align right output */
    cout << n.firstName << " " << n.lastName << endl;
    cout << right << setw(n.first_len) << n.first_len << right << setw(n.last_len + 1) << n.last_len << endl;

    /* Align left output */
    cout << n.firstName << " " << n.lastName << endl;
    cout << left << setw(n.first_len + 1) << n.first_len << left << setw(n.last_len) << n.last_len << endl;

    return 0;
}
