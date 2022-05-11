/*
    handle2DArray.java - Find sum, average of a M * N 2D array and sort each column.
    Author: freeants, All rights reserved.
*/
import java.util.Arrays;
import java.util.concurrent.ThreadLocalRandom; // standard way to genrate random number in Java 1.7 and above

class handle2DArray {
    static int M, N; // Array dimension M * N
    static int a[][]; // The 2D array
    static float sum, average; // the sum and average of the array
    static int col[]; // The working array that saves all the column items

    /*
     * Test if it's an integer input
     */
    static boolean isInteger(final String s) {
        boolean isValidInteger = false;
        try {
            Integer.parseInt(s);
            // s is valid integer
            isValidInteger = true;
        } catch (final NumberFormatException ex) {
            // s is not valid integer
        }
        return isValidInteger;
    }

    /*
     * Generate random number in rang [-100,100]
     */
    static int GenRndNum() {
        return ThreadLocalRandom.current().nextInt(-100, 100);
    }

    /*
     * Build 2D array with random numbers, to save input time
     */
    static void Build2DArray(int m, int n) {
        System.out.println("Build 2D array ... (size: " + m + "*" + n + ")");
        // Define the array
        a = new int[M][N];
        col = new int[M];
        // assign values to array with random number
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                a[i][j] = GenRndNum();
        System.out.println(Arrays.deepToString(a));
    }

    /*
     * Sum up all items in the array.
     */
    static float Sumof2DArray(int m, int n) {
        sum = 0;
        // loop through all items and sum them up
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                sum += a[i][j];
        return sum;
    }

    /*
     * Get the average of the array.
     */
    static float Averageof2DArray(int m, int n) {
        return (float) (sum / (m * n));
    }

    /*
     * Print the sum and average of the array
     */
    static void PrintSumAverage() {
        System.out.println("     Sum of the array: " + Sumof2DArray(M, N));
        System.out.println(" Average of the array: " + Averageof2DArray(M, N));
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
     * Sort array rows and print sorted items.
     */
    static void SortArrayRows(int arr[][]) {

        for (int c = 0; c < N; c++) { // for each col from 0 to N
            for (int r = 0; r < M; r++) {
                col[r] = arr[r][c]; // assign col items to row[] array
            }
            insertionSort(col, M); // sort each col arrays, total N times
            System.out.println("Sorted items @ col[" + c + "]: " + Arrays.toString(col));
        }
    }

    public static void main(String[] args) {
        // Ask for input array size at start
        if (args.length != 2) {
            System.out.println("Usage: Sort2DArray m n");
            return;
        }
        // Input validations
        if (isInteger(args[0]) && isInteger(args[1])) {
            M = Integer.valueOf(args[0]);
            N = Integer.valueOf(args[1]);
        } else {
            System.out.println("M & N need to be integers.");
            return;
        }
        // Meet requirements, start prog
        try {
            // Build the array with random numbers
            Build2DArray(M, N);
            // Print the sum and average of the array
            PrintSumAverage();
            // Sort array rows.
            SortArrayRows(a);
        } catch (Exception e) {
            // Handle exception
            System.out.println("\nError:" + e.getLocalizedMessage());
        }
    }
}