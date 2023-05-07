/*
 * InsertSortTst.cc - freeants, 2020.
 **/

#include <chrono>
#include <random>
#include <iostream>
#include <iomanip>
using namespace std;

const int max_size = 9999; // Size of data dictionary

int *a; // Data dictionary

void insertionSort(int arr[], int length)
{
    int i, j, tmp;
    for (i = 1; i < length; i++)
    {
        j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }
    }
}

/*
 * GenRandNumber() - Generate key number randomly.
 */
int GenRandomNumber()
{
    random_device rd;                              //obtain a random number from hardware
    mt19937 gen(rd());                             //seed the generator
    uniform_int_distribution<> distr(0, max_size); //define the range

    //return the rand value
    return distr(gen);
}

void BuildDataDictionary()
{
    cout << "Building data dictionary ... (size: " << max_size << ") - ";

    auto t0 = chrono::high_resolution_clock::now(); //get start time
    // Define the array that holds all data
    a = new int[max_size];

    // Assign values to array
    for (int i = 0; i < max_size; i++)
        a[i] = GenRandomNumber(); //this forms randomly filled numbers

    auto t1 = chrono::high_resolution_clock::now(); //get end time
    cout << chrono::duration_cast<chrono::microseconds>(t1 - t0).count() << " micro(μ) seconds" << endl;
}

void test()
{
    cout << "Sorting ... " << endl;

    auto t0 = chrono::high_resolution_clock::now(); //get start time
    insertionSort(a, max_size);
    auto t1 = chrono::high_resolution_clock::now(); //get end time
    cout << left << setw(20) << "Insertion -" << setw(20) << chrono::duration_cast<chrono::microseconds>(t1 - t0).count() << endl;
}

int main()
{
    try
    {
        // Instantiation
        BuildDataDictionary();

        // Start test
        test();
    }
    catch (...)
    {
        cout << "ERROR!" << endl;
        return -1;
    }
    delete[] a;
    return 0;
}