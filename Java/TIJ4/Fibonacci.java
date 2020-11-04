package TIJ4;

//:Fibonacci.java

class Fibonacci {
    public static void main(String[] args) {
        int a = 0, b = 1, tmp;
        while (a < 10000) {
            System.out.print(a + ",");
            tmp = a;
            a = b;
            b = tmp + b;
        }
        System.out.println();
    }
}