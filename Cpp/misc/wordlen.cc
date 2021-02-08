//:wordlen.cc - measure some strings.

#include <iostream>
using namespace std;

int main()
{
    int i;
    const string word[3] = {"cat", "windows", "defenestrate"};
    for (i = 0; i < 3; i++)
        cout << word[i] << " " << word[i].length() << endl;
    return 0;
}