
// Java program to find large
// factorials using BigInteger
//Pn = 1 - factorial(365) / (365**n * factorial(365-n))
import java.math.BigInteger;
import java.math.BigDecimal;
import java.util.Scanner;

public class SameBirth {
    static int N;

    // Returns Factorial of N
    static BigInteger factorial(int N) {
        // Initialize result
        BigInteger f = new BigInteger("1"); // Or BigInteger.ONE

        // Multiply f with 2, 3, ...N
        for (int i = 2; i <= N; i++)
            f = f.multiply(BigInteger.valueOf(i));

        return f;
    }

    // Divide two BigIntegers
    static BigInteger diviDec() {
        // Initialize value
        BigInteger p = factorial(365).divide(factorial(365 - N));
        return p;
    }

    // Get input from console
    static void getInput() {
        Scanner reader = new Scanner(System.in);
        System.out.print("N : ");
        N = reader.nextInt();
        reader.close();
    }

    // Driver method
    public static void main(String args[]) throws Exception {
        // int N = 100;
        System.out.println(factorial(N));
    }
}