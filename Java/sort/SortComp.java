package sort;

//import java.util.concurrent.TimeUnit; // for timing the process
import java.util.concurrent.ThreadLocalRandom; // standard way to genrate random number in Java 1.7 and above

public class SortComp {
    static int max_size = 19999; // size of data set
    static int a[]; // the data set array

    /*
     * Bubble Sort method
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
     * Quick Sort method
     */
    static void quickSort(int arr[], int left, int right) {
        int i = left, j = right;
        int tmp;
        int pivot = arr[(left + right) / 2];

        // partition
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
        // recursion
        if (left < j)
            quickSort(arr, left, j);
        if (i < right)
            quickSort(arr, i, right);
    }

    /*
     * Insertion Sort method
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
     * Selection Sort method
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
     * Generate random number
     */
    static int GenRndNum() {
        return ThreadLocalRandom.current().nextInt(0, 101);
    }

    /*
     * Build data set
     */
    static void BuildDataSet(int size) {
        System.out.print("Building data set ... (size: " + size + ") ");
        long startTime = System.nanoTime();
        // define the array
        a = new int[max_size];

        // assign values to array
        for (int i = 0; i < max_size; i++)
            a[i] = GenRndNum();

        long endTime = System.nanoTime();
        long timeElapsed = endTime - startTime;
        System.out.println("- " + timeElapsed / 1000 + " micro(μ) seconds.");
    }

    /*
     * Do the test algorithm seris
     */
    static void test() {
        System.out.println("Sorting ...");

        long t0 = System.nanoTime();
        bubbleSort(a, max_size);
        long t1 = System.nanoTime();
        System.out.println("Bubble - " + (t1 - t0) / 1000);

        selectionSort(a, max_size);
        long t2 = System.nanoTime();
        System.out.println("Select - " + (t2 - t1) / 1000);

        insertionSort(a, max_size);
        long t3 = System.nanoTime();
        System.out.println("Insert - " + (t3 - t2) / 1000);

        quickSort(a, 0, max_size - 1);
        long t4 = System.nanoTime();
        System.out.println("Quick  - " + (t4 - t3) / 1000);

    }

    public static void main(String[] args) {
        try {
            // Instantiation
            BuildDataSet(max_size);

            // Start test
            test();

        } catch (Exception e) {
            System.out.println("ERROR!");
        }
    }
}
