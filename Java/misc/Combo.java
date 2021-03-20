
public class Combo {
    static int doCombo(int m, int n) {
        if (n == 0 || n == m)
            return 1;
        else
            return doCombo(m - 1, n) + doCombo(m - 1, n - 1);
    }

    public static void main(String[] args) {
        int cnt = 0;
        cnt = doCombo(10, 4);
        System.out.println(cnt);
    }
}
