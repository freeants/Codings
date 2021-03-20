/*
   MaximalPairs.java - Test to output the combinations of C(N,M), with other conditions
   Copyright: freeants, All rights reserved.
 */
public class MaximalPairs {
  static int S[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  static int n = 10;
  static int a, b, c, d, e, f, g, h, i, j, A, B;
  static long p;
  static boolean isIdentical(int arr[]) {
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        if (arr[i] == arr[j])
          return false;
    return true;
  }

  public static void main(String[] args) {

    a = 9;
    b = 6;
    c = 4;
    d = 2;
    e = 0;
    f = 8;
    g = 7;
    h = 5;
    i = 3;
    j = 1;

    A = 10000 * a + 1000 * b + 100 * c + 10 * d + e;
    B = 10000 * f + 1000 * g + 100 * h + 10 * i + j;
    //long p;
    p = A * B;

    System.out.println(A + " * " + B + " = " + A * B);
  }
}
