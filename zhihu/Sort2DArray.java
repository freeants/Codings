/*
    Sort2DArray.java - Find max item of each row, output each and their sum.
    Author: freeants, All rights reserved.
*/
import java.util.Arrays;
import java.util.concurrent.ThreadLocalRandom; // standard way to genrate random number in Java 1.7 and above

class Sort2DArray {
    static int M, N; // Array dimension M * N
    static int a[][]; // The 2D array
    static int max[], row[]; // The working array that saves all the max row items

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
        max = new int[M];
        row = new int[N];
        // assign values to array with random number
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                a[i][j] = GenRndNum();
        System.out.println(Arrays.deepToString(a));
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
     * Print Max row item of the array
     */
    static void PrintMaxRowItem(int arr[][]) {

        for (int r = 0; r < M; r++) { // for each row from 0 to M
            for (int c = 0; c < N; c++) {
                row[c] = a[r][c]; // assign row items to row[] array
            }
            insertionSort(row, N); // sort reach row array, total M times
            System.out.println("Max @ row[" + r + "]: " + row[N - 1]);
            max[r] = row[N - 1]; // save each row max to max[]
        }
    }

    /*
     * Sum up max row items
     */
    static void SumMax() {
        int s = 0;
        for (int i = 0; i < M; i++)
            s += max[i];
        System.out.println("Sum of all max row item: " + s);
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
            // Print the biggest of each row
            PrintMaxRowItem(a);
            // Sum up all row maxes and print
            SumMax();
        } catch (Exception e) {
            // Handle exception
            System.out.println("\nError:" + e.getLocalizedMessage());
        }
    }
}