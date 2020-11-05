/*
 * SortComp.cxx - freeants, 2020.
 *  - Compare sort algorithms
 **/

#include <chrono>
#include <random>
#include <iostream>
#include <iomanip>
using namespace std;

int max_size; // Size of data dictionary

int *a; // Data dictionary
int *t; // Temp data dictionary

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

void quickSort(int arr[], int left, int right)
{
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
}

void selectionSort(int arr[], int n)
{
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
}

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
 * GenKeyNumber() - Generate key number randomly.
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

void BuildDataDictionary()
{
    cout << "Building data dictionary ... (size: " << max_size << ") - ";

    auto t0 = chrono::high_resolution_clock::now(); //get start time
    // Define the array that holds all data
    a = new int[max_size];
    t = new int[max_size];

    // Assign values to array
    for (int i = 0; i < max_size; i++)
        a[i] = GenRandomNumber(); //this forms randomly filled numbers

    auto t1 = chrono::high_resolution_clock::now(); //get end time
    cout << chrono::duration_cast<chrono::microseconds>(t1 - t0).count() << " micro(μ) seconds" << endl;
}

void copyArry(int *x, int *y)
{
    for (int i = 0; i < max_size; i++)
        y[i] = x[i];
}

bool isSorted(int *arr)
{
    for (int i = 1; i < max_size; i++)
        if (arr[i] < arr[i - 1])
            return false;
    return true;
}

void test()
{
    cout << "Comparing sort algorithms (C++) ..." << endl;
    cout << left << setw(20) << "Algorithm" << setw(20) << "Time elapsed(μ)"
         << "Is sorted?" << endl;

    auto t0 = chrono::high_resolution_clock::now(); //get start time
    copyArry(a, t);
    bubbleSort(t, max_size);
    auto t1 = chrono::high_resolution_clock::now(); //get end time
    cout << left << setw(20) << "Bubble" << setw(20) << chrono::duration_cast<chrono::microseconds>(t1 - t0).count() << isSorted(t) << endl;

    copyArry(a, t);
    selectionSort(t, max_size);
    auto t2 = chrono::high_resolution_clock::now(); //get end time
    cout << left << setw(20) << "Selection" << setw(20) << chrono::duration_cast<chrono::microseconds>(t2 - t1).count() << isSorted(t) << endl;

    copyArry(a, t);
    insertionSort(t, max_size);
    auto t3 = chrono::high_resolution_clock::now(); //get end time
    cout << left << setw(20) << "Insertion" << setw(20) << chrono::duration_cast<chrono::microseconds>(t3 - t2).count() << isSorted(t) << endl;

    copyArry(a, t);
    quickSort(t, 0, max_size - 1);
    auto t4 = chrono::high_resolution_clock::now(); //get end time
    cout << left << setw(20) << "Quick" << setw(20) << chrono::duration_cast<chrono::microseconds>(t4 - t3).count() << isSorted(t) << endl;

    auto timeElapsed = chrono::duration_cast<chrono::microseconds>(t4 - t0).count();
    cout << "///////////////////////////////////////////////////////" << endl;
    cout << left << setw(20) << "// Total time" << setw(20) << timeElapsed << (double)timeElapsed / 1000000 << " seconds" <<"//"<< endl;
    cout <<left<<setw(20) <<"// Completed @ " <<setw(20) << system <<" //" << endl;
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
    delete[] t;
    return 0;
}