/*
    File: SortCompTh.cc - Compare sort algorithms, multi-threaded way.
    Copyright:  (c) freeants. All rights reserved.
 */
#include <chrono> // for chrono timing
#include <ctime>  // for time()
#include <random> // for random device
#include <iostream>
#include <iomanip>
#include <thread> // the c++ thread classes

using namespace std;

int max_size; // Size of data dictionary

int *a;                          // Data dictionary
int *d0, *d1, *d2, *d3;          // Temp data dictionary, each for a threaded task
auto t_th0, t_th1, t_th2, t_th3; // for each thread executing time

/*
 * The Bubble Sort method.
 */
void bubbleSort(int arr[], int n)
{
    auto t0 = chrono::high_resolution_clock::now(); //get start time
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
    auto t1 = chrono::high_resolution_clock::now(); //get end time
    t_th0 = t1 - t0;                                //get process execution time
}

/*
 * The Selection Sort method.
 */
void selectionSort(int arr[], int n)
{
    auto t0 = chrono::high_resolution_clock::now(); //get start time
    int i, j, minIndex, tmp;
    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;
        if (minIndex != i)
        {
            tmp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = tmp;
        }
    }
    auto t1 = chrono::high_resolution_clock::now(); //get end time
    t_th1 = t1 - t0;
}

/*
 * The Insertion Sort method.
 */
void insertionSort(int arr[], int length)
{
    auto t0 = chrono::high_resolution_clock::now(); //get start time
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
    auto t1 = chrono::high_resolution_clock::now(); //get end time
    t_th2 = t1 - t0;
}

/*
 * The Quick Sort method.
 */
void quickSort(int arr[], int left, int right)
{
    auto t0 = chrono::high_resolution_clock::now(); //get start time
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    /* partition */
    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
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
    auto t1 = chrono::high_resolution_clock::now(); //get end time
    t_th3 = t1 - t0;                                // return process execution time
}

/*
 * GenRandomNumber() - Generate number randomly in rang [0, max_size].
 */
int GenRandomNumber()
{
    random_device rd;                              //obtain a random number from hardware
    mt19937 gen(rd());                             //seed the generator
    uniform_int_distribution<> distr(0, max_size); //define the range

    //return the rand value
    return distr(gen);
}

void getInput()
{
    cout << "Enter the size of data set: ";
    cin >> max_size;
}

/*
 * Build data dictionary and count timing.
 */
void BuildDataDictionary()
{
    cout << "Building data dictionary ... (size: " << max_size << ") - ";

    auto t0 = chrono::high_resolution_clock::now(); //get start time
    // Define the array that holds all data
    a = new int[max_size];
    d0 = new int[max_size];
    d1 = new int[max_size];
    d2 = new int[max_size];
    d3 = new int[max_size];

    // Assign values to array
    for (int i = 0; i < max_size; i++)
        a[i] = GenRandomNumber(); //this forms randomly filled numbers

    auto t1 = chrono::high_resolution_clock::now(); //get end time
    cout << chrono::duration_cast<chrono::microseconds>(t1 - t0).count() << " micro(μ) seconds" << endl;
}

/*
 * Copy array to another.
 */
void copyArry(int *x, int *y)
{
    for (int i = 0; i < max_size; i++)
        y[i] = x[i];
}

/*
 * Verify if the array was sorted.
 */
bool isSorted(int *arr)
{
    for (int i = 1; i < max_size; i++)
        if (arr[i] < arr[i - 1])
            return false;
    return true;
}

/*
 * Main routine that carries out the tests - multi threaded.
 */
void test()
{
    cout << "Comparing sort algorithms (C++, threaded) ..." << endl;
    cout << left << setw(20) << "Algorithm" << setw(20) << "Time elapsed(μ)"
         << "Is sorted? "
         << " Thread ID" << endl;

    /** th0 for bubble sort */

    copyArry(a, d0);
    thread th0(bubbleSort, d0, max_size); // create th0 and get it started
    th0.detach();                         //none blocking way
    cout << left << setw(20) << "Bubble" << setw(20) << chrono::duration_cast<chrono::microseconds>(t_th0).count() << isSorted(d0) << th0.get_id() << endl;

    copyArry(a, d1);
    thread th1(selectionSort, d1, max_size);
    th1.detach();
    cout << left << setw(20) << "Selection" << setw(20) << chrono::duration_cast<chrono::microseconds>(t_th1).count() << isSorted(d1) << th1.get_id() << endl;

    copyArry(a, d2);
    thread th2(insertionSort, d2, max_size);
    th2.detach();
    cout << left << setw(20) << "Insertion" << setw(20) << chrono::duration_cast<chrono::microseconds>(t_th2).count() << isSorted(d2) << endl;

    copyArry(a, d3);
    thread th3(quickSort, 0, max_size);
    th3.detach();
    cout << left << setw(20) << "Quick" << setw(20) << chrono::duration_cast<chrono::microseconds>(t_th3).count() << isSorted(d3) << endl;

    auto timeElapsed = chrono::duration_cast<chrono::microseconds>(t_th0 + t_th1 + t_th2 + t_th3).count();
    auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());
    cout << "////////////////////////////////////////////////////////" << endl;
    cout << left << setw(20) << " Total time" << setw(20) << timeElapsed << (double)timeElapsed / 1000000 << " seconds"
         << endl;
    cout << left << setw(20) << " Completed @ " << setw(20) << ctime(&timenow) << endl;
}

int main()
{
    try
    {
        // Get input
        getInput();

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
    delete[] d0;
    delete[] d1;
    delete[] d2;
    delete[] d3;
    return 0;
}