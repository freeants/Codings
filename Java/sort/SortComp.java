package sort;

import java.util.concurrent.ThreadLocalRandom; // standard way to genrate random number in Java 1.7 and above
import java.util.Arrays;
import java.util.Date;
import java.util.Scanner;

public class SortComp {
    static int max_size; // size of data set
    static int a[]; // the data set array
    static int t[]; // the temp data set

    /*
     * 1. bubbleSort() - Comparision Sort algorithm, exchange sorting O(n²), O(1),
     * Stable
     */
    static void bubbleSort(int arr[], int n) {
        boolean swapped = true;
        int j = 0;
        int tmp;
        while (swapped) {
            swapped = false;
            j++;
            for (int i = 0; i < n - j; i++) {
                if (arr[i] > arr[i + 1]) {
                    tmp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = tmp;
                    swapped = true;
                }
            }
        }
    }

    /*
     * 2. quickSort() - Comparision Sort algorithm, exchange sorting O(nlog(n)),
     * O(nlog(n)), Unstable
     */
    static void quickSort(int arr[], int left, int right) {
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
        }
        ;

        /* recursion */
        if (left < j)
            quickSort(arr, left, j);
        if (i < right)
            quickSort(arr, i, right);
    }

    /*
     * 3. insertionSort() - Comparision Sort algorithm, insertion sorting O(n²),
     * O(1), Stable
     */
    static void insertionSort(int arr[], int n) {
        int i, j, tmp;
        for (i = 1; i < n; i++) {
            j = i;
            while (j > 0 && arr[j - 1] > arr[j]) {
                tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
                j--;
            }
        }
    }

    /*
     * 4. shellSort() - Comparision Sort algorithm, insertion sorting O(n^1.3),
     * O(1), Unstable
     */
    static void shellSort(int arr[], int n) {
        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i++) {
                int j = i;
                int current = arr[i];
                while (j - gap >= 0 && current < arr[j - gap]) {
                    arr[j] = arr[j - gap];
                    j -= gap;
                }
                arr[j] = current;
            }
        }
    }

    /*
     * 5. selectionSort() - Comparision Sort algorithm, selection sorting O(n²),
     * O(1), Unstable
     */
    static void selectionSort(int arr[], int n) {
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

    /*
     * 6. heapSort() - Comparision Sort algorithm, selection sorting O(nlogn), O(1),
     * Unstable
     */
    // To heapify a subtree rooted with node i which is
    // an index in arr[]. n is size of heap
    static void heapify(int arr[], int n, int i) {
        int largest = i; // Initialize largest as root
        int l = 2 * i + 1; // left = 2*i + 1
        int r = 2 * i + 2; // right = 2*i + 2

        // If left child is larger than root
        if (l < n && arr[l] > arr[largest])
            largest = l;

        // If right child is larger than largest so far
        if (r < n && arr[r] > arr[largest])
            largest = r;

        // If largest is not root
        if (largest != i) {
            int tmp;
            // swap(arr[i], arr[largest]);
            tmp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = tmp;

            // Recursively heapify the affected sub-tree
            heapify(arr, n, largest);
        }
    }

    // main function to do heap sort
    static void heapSort(int arr[], int n) {
        // Build heap (rearrange array)
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);

        // One by one extract an element from heap
        for (int i = n - 1; i >= 0; i--) {
            // Move current root to end
            // swap(arr[0], arr[i]);
            int tmp;
            tmp = arr[0];
            arr[0] = arr[i];
            arr[i] = tmp;

            // call max heapify on the reduced heap
            heapify(arr, i, 0);
        }
    }

    /*
     * 7. mergeSort() - Comparision Sort algorithm, merge sorting O(nlog(n)), O(n),
     * Stable
     */
    static void merge(int arr[], int l, int m, int r) {
        // Find sizes of two subarrays to be merged
        int n1 = m - l + 1;
        int n2 = r - m;

        /* Create temp arrays */
        int L[] = new int[n1];
        int R[] = new int[n2];

        /* Copy data to temp arrays */
        for (int i = 0; i < n1; ++i)
            L[i] = arr[l + i];
        for (int j = 0; j < n2; ++j)
            R[j] = arr[m + 1 + j];

        /* Merge the temp arrays */

        // Initial indexes of first and second subarrays
        int i = 0, j = 0;

        // Initial index of merged subarry array
        int k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        /* Copy remaining elements of L[] if any */
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        /* Copy remaining elements of R[] if any */
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    // Main function that sorts arr[l..r] using
    // merge()
    static void mergeSort(int arr[], int l, int r) {
        if (l < r) {
            // Find the middle point
            int m = l + (r - l) / 2;

            // Sort first and second halves
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);

            // Merge the sorted halves
            merge(arr, l, m, r);
        }
    }

    /*
     * 8. bucketSort() - Non-Comparision Sort algorithm, bucket sorting O(n+k),
     * O(n+k), Stable
     */
    static void bucketSort(int arr[], int n, int max) {
        int i, j;
        int buckets[] = new int[max];

        // 1. Counting
        for (i = 0; i < n; i++)
            buckets[arr[i]]++;

        // 2. Sorting
        for (i = 0, j = 0; i < max; i++) {
            while ((buckets[i]--) > 0)
                arr[j++] = i;
        }
    }

    /*
     * Generate random number
     */
    static int GenRndNum() {
        return ThreadLocalRandom.current().nextInt(0, max_size);
    }

    /*
     * Build data set
     */
    static void BuildDataSet(int size) {
        System.out.print("Building data set ... (size: " + size + ") ");
        long startTime = System.nanoTime();
        // define the array
        a = new int[max_size];
        t = new int[max_size];

        // assign values to array
        for (int i = 0; i < max_size; i++)
            a[i] = GenRndNum();

        long endTime = System.nanoTime();
        long timeElapsed = endTime - startTime;
        System.out.println("- " + timeElapsed / 1000 + " micro seconds.");
    }

    static void copyArry(int x[], int y[]) {
        for (int i = 0; i < max_size; i++)
            y[i] = x[i];
    }

    static boolean isSorted(int arr[]) {
        for (int i = 1; i < max_size; i++)
            if (arr[i] < arr[i - 1])
                return false;
        return true;
    }

    static void getInput() {
        Scanner reader = new Scanner(System.in);
        System.out.print("Enter the size of data set: ");
        max_size = reader.nextInt();
        reader.close();
    }

    /*
     * Do the test algorithm seris
     */
    static void test() {
        System.out.println("Sorting (Java)...");

        // Setting up some alignment format
        String leftAlignFormat = "%-16s %-20s %-6s%n";
        System.out.printf(leftAlignFormat, "Algorithm", "Time elapsed ", "Is sorted?");

        long t0 = System.nanoTime();
        copyArry(a, t);
        bubbleSort(t, max_size);
        long t1 = System.nanoTime();
        System.out.printf(leftAlignFormat, "1.Bubble", (t1 - t0) / 1000, isSorted(t));

        copyArry(a, t);
        quickSort(t, 0, max_size - 1);
        long t2 = System.nanoTime();
        System.out.printf(leftAlignFormat, "2.Quick", (t2 - t1) / 1000, isSorted(t));

        copyArry(a, t);
        insertionSort(t, max_size);
        long t3 = System.nanoTime();
        System.out.printf(leftAlignFormat, "3.Insertion", (t3 - t2) / 1000, isSorted(t));

        copyArry(a, t);
        shellSort(t, max_size);
        long t4 = System.nanoTime();
        System.out.printf(leftAlignFormat, "4.Shell", (t4 - t3) / 1000, isSorted(t));

        copyArry(a, t);
        selectionSort(t, max_size);
        long t5 = System.nanoTime();
        System.out.printf(leftAlignFormat, "5.Selection", (t5 - t4) / 1000, isSorted(t));

        copyArry(a, t);
        heapSort(t, max_size);
        long t6 = System.nanoTime();
        System.out.printf(leftAlignFormat, "6.Heap", (t6 - t5) / 1000, isSorted(t));

        copyArry(a, t);
        mergeSort(t, 0, max_size - 1);
        long t7 = System.nanoTime();
        System.out.printf(leftAlignFormat, "7.Merge", (t7 - t6) / 1000, isSorted(t));

        copyArry(a, t);
        bucketSort(t, max_size, max_size + 1);
        long t8 = System.nanoTime();
        System.out.printf(leftAlignFormat, "8.Bucket", (t8 - t7) / 1000, isSorted(t));

        copyArry(a, t);
        Arrays.sort(t);
        long t9 = System.nanoTime();
        System.out.printf(leftAlignFormat, "9.Arrays.sort()", (t9 - t8) / 1000, isSorted(t));

        // Print the summary
        long timeElapsed = t9 - t0;
        System.out.println("////////////////////////////////////////////////////////");
        System.out.printf(leftAlignFormat, " Total time", timeElapsed / 1000,
                ((float) timeElapsed / 1000000000) + " seconds");
        System.out.printf(leftAlignFormat, " Completed @", new Date(), "");
    }

    public static void main(String[] args) {

        try {
            // Get input
            getInput();
            // Instantiation
            BuildDataSet(max_size);
            // Start test
            test();

        } catch (Exception e) {
            System.out.println("ERROR!");
        }
        System.gc();
        System.runFinalization();
    }
}