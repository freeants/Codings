/*
 * bubbleSort.cxx - freeants, 2016.
 **/

#include <chrono>
#include <iostream>

using namespace std;

int *arr;

void bubbleSort(int arr[], int n)
{
  bool swapped = true;
  int j = 0;
  int tmp;
  while (swapped)
  {
    swapped = false;
    j++;
    for (int i = 0; i < n - j; i++)
    {
      if (arr[i] > arr[i + 1])
      {
        tmp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = tmp;
        swapped = true;
      }
    }
  }
}

int main()
{
  int n; //Array size
  cout << "Bubble Sort - " << endl
       << endl
       << "1. Enter array size: ";
  cin >> n;

  arr = new int[n];

  cout << "2. Input " << n << " integers below: " << endl;

  for (int i = 0; i < n; ++i)
    cin >> arr[i];

  auto begin = chrono::high_resolution_clock::now(); //get start time
  bubbleSort(arr, n);
  auto end = chrono::high_resolution_clock::now(); //get end time
  cout << "3. Ascending order sorted: " << endl;
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";

  cout << endl
       << endl
       << "Elasped time: " << chrono::duration_cast<chrono::nanoseconds>(end - begin).count() << " nano seconds" << endl;

  delete arr;
  return 0;
}
