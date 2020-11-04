package ALGO4;

public class test {
    public static void main(final String[] args) {
        final int N = 3;
        final int[][] a = new int[N][N];
        int val = 0;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                a[i][j] = val++;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                System.out.print(" " + a[i][j]);
            System.out.print("\n");
        }
    }
}