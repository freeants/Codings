/**
 * SearchComp.cc - Compare search algorithems.
 * (c), freeansts. All rights reserved.
 **/

#include <cstring>
#include <iostream>
#include <random>
#include <cctype>
#include <iomanip>
#include <chrono>
using namespace std;

const int max_size = 500000; // Size of Fibonacci array
const int MAX = max_size / 2; // Size of data dictionary
const int MIN = -(max_size / 2);

int *arr; // Gloable data dictionary
int key;  // The key number to be searched for

/* 1.
 * SequenceSearch - linear search
 * Average Search Length (ASL) = (n+1) / 2, O(n).
 */
int SequenceSearch(int *a, int key, int n)
{
    for (int i = 0; i < n; i++)
        if (a[i] == key)
            return i;
    return -1;
}

/* 2.
 * BinarySearch - Ordered search
 * ASL = log2(n+1), O(log2n)
 */
int BinarySearch(int *a, int key, int n)
{
    int mid, low = 0, high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == key)
            return mid;
        if (a[mid] > key)
            high = mid - 1;
        if (a[mid] < key)
            low = mid + 1;
    }
    return -1;
}

/* 3.
 * InsertionSearch - improved binary search
 * O(log2(log2n))
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
 * Fibonacci(int *) - construct a Fibonacci array
 */
void Fibonacci(int *F)
{
    F[0] = 0;
    F[1] = 1;
    for (int i = 2; i < max_size; ++i)
        F[i] = F[i - 1] + F[i - 2];
}

/* 4.
 * FibonacciSearch - Improved binary search.
 * O(log2n)
 */
int FibonacciSearch(int *a, int key, int n)
{
    int F[max_size];
    int low = 0, high = n - 1;
    Fibonacci(F); // to form an F array
    int k = 0;
    while (n > F[k] - 1)
        ++k;

    int *temp; // extend length of a to that of F[k] -1
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
 * Test if it's an integer input
 */
bool isInteger(const char *s)
{
    bool isValidInteger = true;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (!isdigit(s[i]))
            isValidInteger = false;
    }
    return isValidInteger;
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
    return distr(gen);
}

void BuildDataDictionary()
{
    // Define the array that holds all data
    arr = new int[MAX];

    // Assign values to array
    for (int i = MIN; i <= MAX; i++)
    {
        arr[i] = i; //this forms a sorted serise of [MIN, MAX]
        //arr[i] = GenKeyNumber(); //this forms randomly filled numbers
        //cout << arr[i] << " ";
    }
}

/*
 * Display search results - Lambda expression way.
 */
static auto dispResult = [](string str, int index, auto diffTime) {
    if (index != -1)
        cout << left << setw(20) << str << " key(" << key << ") found @ index: " << index << ", " << chrono::duration_cast<chrono::microseconds>(diffTime).count() << " ms." << endl;
    else
        cout << left << setw(20) << str << " key(" << key << ") NOT found, " << chrono::duration_cast<chrono::microseconds>(diffTime).count() << " ms." << endl;
};

void test()
{
    int index;

    cout << "Dataset rang - [" << MIN << ", " << MAX << "]" << endl;
    auto t0 = chrono::high_resolution_clock::now(); //get start time
    
    index = SequenceSearch(arr, key, MAX);
    auto t1 = chrono::high_resolution_clock::now(); //get start time
    dispResult("1. SequenceSearch", index, t1 - t0);

    index = BinarySearch(arr, key, MAX);
    auto t2 = chrono::high_resolution_clock::now(); //get start time
    dispResult("2. BinarySearch", index, t2 - t1);

    index = InsertionSearch(arr, key, MIN, MAX - 1);
    auto t3 = chrono::high_resolution_clock::now(); //get start time
    dispResult("3. InsertionSearch", index, t3 - t2);

    index = FibonacciSearch(arr, key, MAX);
    auto t4 = chrono::high_resolution_clock::now(); //get start time
    dispResult("4. FibonacciSearch", index, t4 - t3);
}

int main(int argc, char const *argv[])
{
    // Check cmd line args
    //if (argc != 2)
    //{
    //    cerr << "Usage: SearchComp key" << endl;
    //    return 1;
    //}

    //if (isInteger(argv[1]))
    //{
    //    key = stoi(argv[1]);
    //}
    //else
    //{
    //    cerr << "key needs to be an integer." << endl;
    //    return 1;
    //}

    try
    {
        // Instantiation
        BuildDataDictionary();
        // Generate key
        key = GenKeyNumber();
        // Start test
        test();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    delete[] arr;
    return 0;
}