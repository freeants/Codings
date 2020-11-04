/*
 * quickSort.cxx - freeants, 2016.
 **/

#include <chrono>
#include <iostream>

using namespace std;

int *arr;

void quickSort(int arr[], int left, int right) {
  int i = left, j = right;
  int tmp;
  int pivot = arr[(left + right) / 2];
 
  /* partition */
  while (i <= j) {
    while (arr[i] < pivot)
      i++;
    while (arr[j] > pivot)
      j--;
    if (i <= j) {
      tmp = arr[i];
      arr[i] = arr[j];
      arr[j] = tmp;
      i++;
      j--;
    }
  };
 
  /* recursion */
  if (left < j)
    quickSort(arr, left, j);
  if (i < right)
    quickSort(arr, i, right);
}
	
int main()
{
  int n; //Array size
  cout <<"Quick Sort - " <<endl <<endl <<"1. Enter array size: ";
  cin >> n;

  arr = new int[n];
  
  cout <<"2. Input " <<n <<" integers below: " <<endl;
  
  for (int i = 0; i < n; ++i)
    cin >> arr[i];

  auto begin = chrono::high_resolution_clock::now(); //get start time
  quickSort(arr, 0, n-1);
  auto end = chrono::high_resolution_clock::now();  //get end time
  cout <<"3. Ascending order sorted: " <<endl;
  for (int i = 0; i < n; i++)
    cout << arr[i] <<" ";

  cout <<endl <<endl <<"Elasped time: "<<chrono::duration_cast<chrono::nanoseconds>(end - begin).count() <<" nano seconds" <<endl;
  
  delete arr;
  return 0;
}
