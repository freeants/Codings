#include <iostream>

using namespace std;

int main()
{
    int table[10][23];

    for (int i = 0; i < 10; ++i)
    {
        table[i][0] = i;
        for (int j = 1; j < 23; ++j)
        {
            table[i][j] = (table[i][j - 1] + 10) % 23;
        }
    }

    int c;
    int mod = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            printf("%d\n", mod);
            mod = 0;
        }
        else
        {
            // c in '0'...'9'
            c -= '0';
            mod = table[c][mod];
        }
    }

    return 0;
}