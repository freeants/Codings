/**
 * SearchComp.cc - Compare search algorithems.
 * (c), freeansts. All rights reserved.
 **/

#include <cstring>
#include <iostream>
#include <random>
using namespace std;

const int max_size = 200; // Size of Fibonacci array
const int MAX = 200;      // Size of data dictionary
const int MIN = 0;

int *arr; // Gloable data dictionary
int key;  // The key number to be searched for
int Ci;   // Compare times when element i is found

clock_t t0, t1, t2, t3, t4; // Time

/*
 * Fibonacci(int *) - construct a Fibonacci array
 */
void Fibonacci(int *F)
{
    F[0] = 0;
    F[1] = 1;
    for (int i = 2; i < max_size; ++i)
        F[i] = F[i - 1] + F[i - 2];
}

/*
 * SequenceSearch(int *, int key, int n)
 */
int SequenceSearch(int *a, int key, int n)
{
    for (int i = 0; i < n; i++)
        if (a[i] == key)
            return i;
    return -1;
}

/*
 * BinarySearch(int *, int key, int n)
 */
int BinarySearch(int *a, int key, int n)
{
    int mid, low = 0, high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] > key)
            high = mid - 1;
        else if (a[mid] < key)
            low = mid + 1;
    }
    return -1;
}

/*
 * InsertionSearch(int *, int key, int low, int high)
 */
int InsertionSearch(int *a, int key, int low, int high)
{
    if (low <= high)
    {
        int mid = low + (key - a[low]) / (a[high] - a[low]) * (high - low);
        if (a[mid] == key)
            return mid;
        if (a[mid] > key)
            return InsertionSearch(a, key, low, mid - 1);
        if (a[mid] < key)
            return InsertionSearch(a, key, mid + 1, high);
    }
    return -1;
}

/*
 * FibonacciSearch(int *, int n, int key)
 */
int FibonacciSearch(int *a, int n, int key)
{
    int F[max_size];
    int low = 0, high = n - 1;
    Fibonacci(F); // to form an F array
    int k = 0;
    while (n > F[k] - 1)
        ++k;

    int *temp; // exten length of a to that of F[k] -1
    temp = new int[F[k] - 1];
    memcpy(temp, a, n * sizeof(int));
    for (int i = n; i < F[k] - 1; ++i)
        temp[i] = a[n - 1];

    while (low <= high)
    {
        int mid = low + F[k - 1] - 1;
        if (key < temp[mid])
        {
            high = mid - 1;
            k -= 1;
        }
        else if (key > temp[mid])
        {
            low = mid + 1;
            k -= 2;
        }
        else
        {
            if (mid < n)
                return mid;
            else

                return n - 1;
        }
    }
    delete[] temp;
    return -1;
}

/*
 * GenKeyNumber() - Generate key number randomly.
 */
int GenKeyNumber()
{
    random_device rd;                           //obtain a random number from hardware
    mt19937 gen(rd());                          //seed the generator
    uniform_int_distribution<> distr(MIN, MAX); //define the range

    //assign the rand value to key number
    key = distr(gen);
    return key;
}

void BuildDataDictionary()
{
    // Define the array that holds all data
    arr = new int[MAX];

    // Assign values to array
    for (int i = 0; i < MAX; i++)
        arr[i] = i; //this forms a sorted serise of [MIN, MAX]
                    //arr[i] = GenKeyNumber(); //this forms randomly filled numbers
}

void test()
{
    int index;
    t0 = clock(); // Time (start)
    // Do Fibnacci search
    index = FibonacciSearch(arr, MAX, key);
    t1 = clock(); // Time (end of computation)
    cout << key << " by FibonacciSearch() is located at: " << index << endl;
    cout << (double)(t1 - t0) / CLOCKS_PER_SEC << " seconds." << endl;

    index = BinarySearch(arr, key, MAX);
    t2 = clock();
    cout << key << " by BinarySearch() is located at: " << index << endl;
    cout << (double)(t2 - t1) / CLOCKS_PER_SEC << " seconds." << endl;

    index = InsertionSearch(arr, key, MIN, MAX);
    t3 = clock();
    cout << key << " by InsertionSearch() is located at: " << index << endl;
    cout << (double)(t3 - t2) / CLOCKS_PER_SEC << " seconds." << endl;

    index = SequenceSearch(arr, key, MAX);
    cout << key << " by SequenceSearch() is located at: " << index << endl;
    cout << (double)(t4 - t3) / CLOCKS_PER_SEC << " seconds." << endl;
}

int main()
{
    try
    {
        // Instantiation
        BuildDataDictionary();

        // Generate the key value to be searched for
        GenKeyNumber();

        // Start test
        test();
    }
    catch (...)
    {
        cout << "ERROR!" << endl;
        return -1;
    }
    delete[] arr;
    return 0;
}