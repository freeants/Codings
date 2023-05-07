package misc;
/*
 *  ComboOf10.java - Test to output the combinations of a+b+c+d = 10, when either a->d >=5
 *  Copyright: freeants, All rights reserved.
 */
class ComboOf10 {
    static int a, b, c, d, cnt;
    static int N = 10;

    static boolean IsSumRight(int a, int b, int c, int d) {
        if (a + b + c + d == N)
            return true;
        else
            return false;
    }

    static boolean IsRestRight(int a, int b, int c, int d) {
        boolean t1 = false, t2 = false;
        t1 = (a >= 5 || b >= 5 || c >= 5 | d >= 5);
        t2 = (a != b && a != c && a != d) && (b != c && b != d && c != d);
        if (t1 && t2)
            return true;
        else
            return false;
    }

    public static void main(String[] args) {
        for (cnt = 0, a = 1; a < N; a++)
            for (b = 1; b < N; b++)
                for (c = 1; c < N; c++)
                    for (d = 1; d < N; d++) {
                        if (IsSumRight(a, b, c, d) && IsRestRight(a, b, c, d)) {
                            cnt++;
                            System.out.println(cnt + ": " + a + b + c + d + " = " + N);
                        }
                    }
    }
}