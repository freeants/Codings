#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    unsigned long int n;
    string s, tmp;

    int Mon, Day, i = 0;
    string sMon, sDay;

    clock_t t0, t1;

    // Time (start)
    t0 = clock();

    for (n = 20200202; n <= 20601231; n++)
    {
        s = to_string(n);
        tmp = s;

        sMon = s.substr(4, 2); // Get Month in string
        Mon = stoi(sMon);      // Month in integer
        if (Mon <= 12 && Mon >= 1)
        {
            sDay = s.substr(6, 2); // Get Day in string
            Day = stoi(sDay);      // Day in integer
            if (Day <= 31 && Day >= 1)
            {
                reverse(tmp.begin(), tmp.end());
                if (s == tmp)
                {
                    cout << ++i << ". " << n << endl;
                }
            }
        }
    }

    // Time (end)
    t1 = clock();
    cout << endl
         << "Totally " << i << " dates found, "
         << (double)(t1 - t0) / CLOCKS_PER_SEC << " seconds elapsed." << endl;
    return 0;
}