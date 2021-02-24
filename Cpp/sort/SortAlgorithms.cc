/*
    File    :   SortAlgorithms.cc - In demostrating and comparision of various sort methods.
    Author  :   freeants (c), All rights reserved.
    Version :   v0.1 Feb 23, 2021. 
*/

#include <chrono>
#include <ctime>
#include <random>
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

/*
 * Gloabl vars
 */
int max_size; // Size of data dictionary
int *a;       // Data dictionary
int *t;       // Temp data dictionary

/* Swap(int *, int *)
 * Swap the value of two elements.
 */
void Swap(int *xp, int *yp)
{
    /* Swap using a third variable tmp, traditional swapping method, base
        int tmp = *xp;
        *yp = *xp;
        *xp = tmp;
     */

    /* Swap using bitwise XOR, sequence point introduced using comma, fast 
        (*xp ^= *yp), (*yp ^= *xp), (*xp ^= *yp);
    */

    /* Inline asm for optimal performance, portable to all platform, fastest */
    asm(""
        : "=r"(*xp), "=r"(*yp)
        : "1"(*xp), "0"(*yp));
}

/* isSorted(int *, int)
 * Verify if the array was sorted.
 */
bool isSorted(int *arr, int n)
{
    for (int i = 1; i < n; i++)
        if (arr[i] < arr[i - 1])
            return false;
    return true;
}

/*
 * Lamda expression for displaying stats.
 */
static auto dispResult = [](string str, auto diffTime, int *arr) {
    cout << left << setw(20) << str << setw(20) << chrono::duration_cast<chrono::microseconds>(diffTime).count() << isSorted(arr, max_size) << endl;
};

/*1. bubbleSort(int A[], int n)
 * Bubble sort, sometimes referred to as sinking sort, is a simple sorting algorithm that
 * repeatedly steps through the list, compares adjacent elements and swaps them if they 
 * are in the wrong order. The pass through the list is repeated until the list is sorted.
 * The algorithm, which is a comparison sort, is named for the way smaller or larger 
 * elements "bubble" to the top of the list. This simple algorithm performs poorly 
 * in real world use and is used primarily as an educational tool.
 * 
 * Worst-case performance: O(n²)/O(n²) comparisons/swaps
 * Best-case performance : O(n)/O(1) 
 * Average performance   : O(n²)/O(n²)
 * Worst-case space complexity: O(1)/O(1) total/auxiliary
 * Stable: yes, Method: Exchanging, Note: Tiny code size
 */
void bubbleSort(int A[], int n)
{
    int newn;
    while (n > 1)
    {
        newn = 0;
        for (int i = 1; i < n; i++)
        {
            if (A[i - 1] > A[i])
            {
                Swap(&A[i - 1], &A[i]);
                newn = i;
            }
        }
        n = newn;
    }
}

/*2. quickSort(int A[], int lo, int hi)
 * Quicksort is a divide-and-conquer algorithm. It works by selecting a 'pivot' element
 * from the array and partitioning the other elements into two sub-arrays, according 
 * to whether they are less than or greater than the pivot. The sub-arrays are then 
 * sorted recursively. This can be done in-place, requiring small additional amounts of 
 * memory to perform the sorting. 
 * Quicksort is a comparison sort, meaning that it can sort items of any type for 
 * which a "less-than" relation (formally, a total order) is defined. Efficient 
 * implementations of Quicksort are not a stable sort, meaning that the relative order 
 * of equal sort items is not preserved.
 * 
 * Worst-case performance: O(n²)
 * Best-case performance : O(n log n)
 * Average performance   : O(n log n)
 * Worst-case space complexity: O(log n)
 * Stable: No, Method: Partitioning, Note: in-place with O(log n) stack space 
 */
void quickSort(int A[], int lo, int hi)
{
    int i = lo, j = hi;
    int tmp;
    int pivot = A[(lo + hi) / 2];

    /* partition */
    while (i <= j)
    {
        while (A[i] < pivot)
            i++;
        while (A[j] > pivot)
            j--;
        if (i <= j)
        {
            Swap(&A[i], &A[j]);
            i++;
            j--;
        }
    };

    /* recursion */
    if (lo < j)
        quickSort(A, lo, j);
    if (i < hi)
        quickSort(A, i, hi);
}

/* 3. insertionSort(int A[], int n)
 * Insertion sort is a simple sorting algorithm that is relatively efficient for
 * small lists and mostly sorted lists, and is often used as part of more sophisticated 
 * algorithms. It works by taking elements from the list one by one and inserting 
 * them in their correct position into a new sorted list similar to how we put money 
 * in our wallet. In arrays, the new list and the remaining elements can share the 
 * array's space, but insertion is expensive, requiring shifting all following elements 
 * over by one. Shellsort is a variant of insertion sort that is more efficient 
 * for larger lists.
 * 
 * Worst-case performance: O(n²)/O(n²) comparisons/swaps
 * Best-case performance : O(n)/O(1) 
 * Average performance   : O(n²)/O(n²)
 * Worst-case space complexity: O(n)/O(1) total/auxiliary
 * Stable: yes, Method: Insertion, Note: O(n + d), in the worst case over sequences that have d inversions.
 */
void insertionSort(int A[], int n)
{
    int i, j;
    for (i = 1; i < n; i++)
    {
        j = i;
        while (j > 0 && A[j - 1] > A[j])
        {
            Swap(&A[j], &A[j - 1]);
            j--;
        }
    }
}

/* 4.
 * shellSort() - Comparision Sort algorithm, insertion sorting
 * O(n^1.3), O(1), Unstable
 */
void shellSort(int A[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int j = i;
            int current = A[i];
            while (j - gap >= 0 && current < A[j - gap])
            {
                A[j] = A[j - gap];
                j -= gap;
            }
            A[j] = current;
        }
    }
}

/* 5.
 * selectionSort() - Comparision Sort algorithm, selection sorting
 * O(n²), O(1), Unstable
 */
void selectionSort(int A[], int n)
{
    int i, j, minIndex;
    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < n; j++)
            if (A[j] < A[minIndex])
                minIndex = j;
        if (minIndex != i)
            Swap(&A[i], &A[minIndex]);
    }
}

/* 6.
 * heapSort() - Comparision Sort algorithm, selection sorting
 * O(nlogn), O(1), Unstable
 */
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int A[], int n, int i)
{
    int largest = i;   // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && A[l] > A[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && A[r] > A[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        Swap(&A[i], &A[largest]);
        // Recursively heapify the affected sub-tree
        heapify(A, n, largest);
    }
}
// main function to do heap sort
void heapSort(int A[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(A, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--)
    {
        // Move current root to end
        Swap(&A[0], &A[i]);
        // call max heapify on the reduced heap
        heapify(A, i, 0);
    }
}

/* 7.
 * mergeSort() - Comparision Sort algorithm, merge sorting
 * O(nlog(n)), O(n), Stable
 */
void merge(int A[], int low, int mid, int high)
{

    int i = low, j = mid + 1, k = 0;
    int *tmp = new int[high - low + 1];
    while (i <= mid && j <= high)
    {
        if (A[i] <= A[j])
            tmp[k++] = A[i++];
        else
            tmp[k++] = A[j++];
    }
    while (i <= mid)
        tmp[k++] = A[i++];
    while (j <= high)
        tmp[k++] = A[j++];
    for (i = low, k = 0; i <= high; i++, k++)
        A[i] = tmp[k];
    delete[] tmp;
}
void mergeSort(int A[], int lo, int hi)
{
    if (lo >= hi)
    {
        return;
    }
    int mid = lo + (hi - lo) / 2;
    mergeSort(A, lo, mid);
    mergeSort(A, mid + 1, hi);
    merge(A, lo, mid, hi);
}

/* 8.
 * bucketSort() - Non-Comparision Sort algorithm, bucket sorting
 * O(n+k), O(n+k), Stable
 */
void bucketSort(int A[], int n, int max)
{
    int i, j;
    int buckets[max];

    // Initiate all values to 0 in buckets
    memset(buckets, 0, max * sizeof(int));

    // 1. counting
    for (i = 0; i < n; i++)
        buckets[A[i]]++;

    // 2. sorting
    for (i = 0, j = 0; i < max; i++)
    {
        while ((buckets[i]--) > 0)
            A[j++] = i;
    }
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
    t = new int[max_size];

    random_device rd;                              //obtain a random number from hardware
    mt19937 gen(rd());                             //seed the generator
    uniform_int_distribution<> distr(0, max_size); //define the range
    // Assign values to array
    for (int i = 0; i < max_size; i++)
        a[i] = distr(gen); //this forms randomly filled numbers

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
 * Main routine that carries out the tests.
 */
void test()
{
    cout << "***Comparing sort algorithms (C++) ..." << endl;
    cout << left << setw(20) << "Algorithm" << setw(20) << "Time elapsed(μ)"
         << "Is sorted?" << endl;

    auto t0 = chrono::high_resolution_clock::now(); //get start time
    copyArry(a, t);
    bubbleSort(t, max_size);
    auto t1 = chrono::high_resolution_clock::now(); //get end time
    dispResult("1.Bubble", t1 - t0, t);

    copyArry(a, t);
    quickSort(t, 0, max_size - 1);
    auto t2 = chrono::high_resolution_clock::now(); //get end time
    dispResult("2.Quick", t2 - t1, t);

    copyArry(a, t);
    insertionSort(t, max_size);
    auto t3 = chrono::high_resolution_clock::now(); //get end time
    dispResult("3.Insertion", t3 - t2, t);

    copyArry(a, t);
    shellSort(t, max_size);
    auto t4 = chrono::high_resolution_clock::now(); //get end time
    dispResult("4.Shell", t4 - t3, t);

    copyArry(a, t);
    selectionSort(t, max_size);
    auto t5 = chrono::high_resolution_clock::now(); //get end time
    dispResult("5.Selection", t5 - t4, t);

    copyArry(a, t);
    heapSort(t, max_size);
    auto t6 = chrono::high_resolution_clock::now(); //get end time
    dispResult("6.Heap", t6 - t5, t);

    copyArry(a, t);
    mergeSort(t, 0, max_size - 1);
    auto t7 = chrono::high_resolution_clock::now(); //get end time
    dispResult("7.Merge", t7 - t6, t);

    copyArry(a, t);
    bucketSort(t, max_size, max_size + 1);
    auto t8 = chrono::high_resolution_clock::now(); //get end time
    dispResult("8.Bucket", t8 - t7, t);

    auto timeElapsed = chrono::duration_cast<chrono::microseconds>(t8 - t0).count();
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
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    delete[] a; // free resources
    delete[] t;
    return 0;
}