package ALGO4;

/*
 * mmm.java - Multi-Multi array Multiply
 */
import java.util.Arrays;

public class mmm {
    public static void main(final String[] args) {
        final int N = 3; // dimention size
        final int[][] a = new int[N][N];
        final int[][] b = new int[N][N];
        final int[][] c = new int[N][N];
        int val = 0;

        // assign values to a & b
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                a[i][j] = b[j][i] = val++;

        // loops to calculate c = a * b
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                for (int k = 0; k < N; k++)
                    c[i][j] += a[i][k] * b[k][j];

        // output a, b and c
        System.out.println(Arrays.deepToString(a));
        System.out.println(Arrays.deepToString(b));
        System.out.println(Arrays.deepToString(c));
        /*
         * for (int i = 0; i < N; i++) { for (int j = 0; j < N; j++)
         * System.out.printf("%6d ", c[i][j]); System.out.println(); }
         */
    }
}