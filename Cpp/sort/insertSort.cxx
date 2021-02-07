/*
 * insertSort.cxx - freeants, 2016.
 **/

#include <chrono>
#include <iostream>

using namespace std;

int *arr;

void insertionSort(int arr[], int length) {
  int i, j, tmp;
  for (i = 1; i < length; i++) {
    j = i;
    while (j > 0 && arr[j - 1] > arr[j]) {
      tmp = arr[j];
      arr[j] = arr[j - 1];
      arr[j - 1] = tmp;
      j--;
    }
  }
}
	
int main()
{
  int n; //Array size
  cout <<"Insertion Sort - " <<endl <<endl <<"1. Enter array size: ";
  cin >> n;

  arr = new int[n];
  
  cout <<"2. Input " <<n <<" integers here: " <<endl;
  //auto begin = chrono::high_resolution_clock::now();

  for (int i = 0; i < n; ++i)
    cin >> arr[i];

  auto begin = chrono::high_resolution_clock::now(); //get start time
  insertionSort(arr, n);
  auto end = chrono::high_resolution_clock::now();  //get end time
  cout <<"3. Ascending order sorted: " <<endl;
  for (int i = 0; i < n; i++)
    cout << arr[i] <<" ";

  cout <<endl <<endl <<"Elasped time: "<<chrono::duration_cast<chrono::nanoseconds>(end - begin).count() <<" nano seconds" <<endl;
  
  delete arr;
  return 0;
}
