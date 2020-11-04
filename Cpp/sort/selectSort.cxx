/*
 * selectSort.cxx - freeants, 2016.
 **/

#include <chrono>
#include <iostream>

using namespace std;

int *arr;

void selectionSort(int arr[], int n) {
  int i, j, minIndex, tmp;    
  for (i = 0; i < n - 1; i++) {
    minIndex = i;
    for (j = i + 1; j < n; j++)
      if (arr[j] < arr[minIndex])
	minIndex = j;
    if (minIndex != i) {
      tmp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = tmp;
    }
  }
}
	
int main()
{
  int n; //Array size
  cout <<"Selection Sort - " <<endl <<endl <<"1. Enter array size: ";
  cin >> n;

  arr = new int[n];
  
  cout <<"2. Input " <<n <<" integers here: " <<endl;
  //auto begin = chrono::high_resolution_clock::now();

  for (int i = 0; i < n; ++i)
    cin >> arr[i];

  auto begin = chrono::high_resolution_clock::now(); //get start time
  selectionSort(arr, n);
  auto end = chrono::high_resolution_clock::now();  //get end time
  cout <<"3. Ascending order sorted: " <<endl;
  for (int i = 0; i < n; i++)
    cout << arr[i] <<" ";
  cout <<endl <<endl <<"Elasped time: "<<chrono::duration_cast<chrono::nanoseconds>(end - begin).count() <<" nano seconds" <<endl;
  
  delete arr;
  return 0;
}
