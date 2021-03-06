
/*
   ComboTest.java - Test to output the combinations of C(N,M), with other conditions.
   Copyright: freeants, All rights reserved.
 */
import java.util.Arrays;
import java.util.Vector;

public class CombTest {
    static int cnt = 0; // counter of satisfactory combinations
    static int S = 10, Num = 5; // one of the conditon that sum needs to equal to 10
    static int N, M; // for C(N, M)
    static Vector<Integer> v;// holds each number in [1, N)

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
     * Build vector v, holds each number in [1, N)
     */
    static void BuildNums(int n) {
        v = new Vector<>();
        for (int i = 1; i <= N; i++)
            v.add(i);
        System.out.println("Number choices: " + v);
    }

    static void otherConditions(int[] solution, int s) {
        int sum = 0;
        boolean c = false;
        for (int i = 0; i < solution.length; i++) {
            sum += solution[i];
            if (solution[i] >= Num) {
                c = true;
            }
        }
        if ((sum == S) && c) {
            System.out.println(++cnt + ":" + Arrays.toString(solution));
        }

    }

    /*
     * Calculate the Combinations of C[N,M]
     * @param v: holds all possiable choices
     * @param solutions: M
     * @param start: starting index
     * @param pos: current position index
     */
    static int Combo(Vector<Integer> v, int[] solution, int start, int pos) {
        if ((pos == solution.length)) {
            // print combinations when other conditions meet
            otherConditions(solution, S);
            return 1;
        }
        int count = 0;
        for (int i = start; i < v.size(); i++) {
            solution[pos++] = v.get(i);
            count += Combo(v, solution, i + 1, pos);
            pos--;
        }
        return count;
    }

    public static void main(String[] args) {
        // Ask for input N, M at start
        if (args.length != 2) {
            System.out.println("Usage: ComboTest N M     // N > M and both integers");
            return;
        }
        // Input validations
        if (isInteger(args[0]) && isInteger(args[1])) {
            N = Integer.valueOf(args[0]);
            M = Integer.valueOf(args[1]);
        } else {
            System.out.println("Note: M > N and need to be integers.");
            return;
        }

        int[] Solution = new int[M];

        try {
            // Build Vector v and fillin with [0-N)
            BuildNums(N);
            // Calculate Combo of C(N,M) with other conditions
            System.out.println(
                    Combo(v, Solution, 0, 0) + " solutions in total and " + cnt + " combos meet requirements.");
        } catch (Exception e) {
            // Handle exception
            System.out.println("\nError:" + e.getLocalizedMessage());
        }
    }
}