/*
   NarcisNum.cc
*/

#include <iostream>
#include <chrono>

using namespace std;

int main()
{
	int i, j, k, l, m;
	int num;

	cout << "Narcissistic numbers within [100, 99999]" << endl;
	auto begin = chrono::high_resolution_clock::now(); //get start time
	for (i = 0; i <= 9; i++)
		for (j = 0; j <= 9; j++)
			for (k = 0; k <= 9; k++)
			{
				num = i * 100 + j * 10 + k;
				if (i * i * i + j * j * j + k * k * k == num && num > 100 && num < 999)
					cout << num << endl;
				for (l = 0; l <= 9; l++)
				{
					num = i * 1000 + j * 100 + k * 10 + l;
					if (i * i * i * i + j * j * j * j + k * k * k * k + l * l * l * l == num && num > 1000 && num < 9999)
						cout << num << endl;
					for (m = 0; m <= 9; m++)
					{
						num = i * 10000 + j * 1000 + k * 100 + l * 10 + m;
						if (i * i * i * i * i + j * j * j * j * j + k * k * k * k * k + l * l * l * l * l + m * m * m * m * m == num && num > 10000)
							cout << num << endl;
					}
				}
			}
	auto end = chrono::high_resolution_clock::now(); //get end time
	cout << endl
		 << endl
		 << "Elasped time: " << chrono::duration_cast<chrono::nanoseconds>(end - begin).count() << " nano seconds" << endl;

	return 0;
}
