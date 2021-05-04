#include <iostream>
#include <string>
using namespace std;

bool judge(int x)
{
    string s, r;
    s = to_string(x);
    r = s;
    reverse(r.begin(), r.end());
    if (s == r)
        return true;
    else
        return false;
}

int main(int argc, char const *argv[])
{
    size_t n;
    cout << "Input a number for testing: ";
    cin >> n;

    if (judge(n))
        cout << n << " is a Plalindrome number." << endl;
    else
        cout << n << " is NOT a Plalindrome number." << endl;

    return 0;
}
