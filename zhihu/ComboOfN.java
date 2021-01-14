/*
   ComboOfN.java - Test to output the combinations of C(N,M), with other conditions
   Copyright: freeants, All rights reserved.
 */

import java.util.Stack;
import java.util.Arrays;
import java.util.Enumeration;

public class ComboOfN {
    static Stack<Integer> stack = new Stack<Integer>();
    static int M, N; // for C(N, M)
    static int Nums[]; // holds each number in [1, N]
    static int cnt = 0;

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
     * Build array Nums[N], holds each number in [1, N]
     */
    static void BuildNumsArray(int n) {
        Nums = new int[n];
        // assign values to array with random number
        for (int i = 0; i < n; i++)
            Nums[i] = i + 1;
        System.out.println(Arrays.toString(Nums));
    }

    /*
     * Save into stack of all the combinations of C[M, N]
     */
    static void CalculateCombo(int num[], int m, int has, int cur) {
        if (has == m) {
            // if (MeetOtherConditions())
            System.out.println(++cnt + ". " + stack);
            return;
        }

        for (int i = cur; i < num.length; i++) {
            if (!stack.contains(num[i])) {
                stack.add(num[i]);
                CalculateCombo(num, m, has + 1, i);
                stack.pop();
            }
        }
    }

    // static int Combo(int m, int n) {
    // if (n == 0 || n == m)
    // return 1;
    // else
    // return Combo(m - 1, n) + Combo(m - 1, n - 1);
    // }

    /*
     * tests other conditions
     */
    static boolean MeetOtherConditions() {
        // Creating an empty enumeration to store
        Enumeration<Integer> enu = stack.elements();
        int sum = 0;
        while (enu.hasMoreElements()) {
            // System.out.println(enu.nextElement()+1);
            sum += enu.nextElement();
        }

        if (sum == N) {
            stack.pop();
            return true;
        } else
            return false;
    }

    public static void main(String[] args) {
        // Ask for input array size at start
        if (args.length != 2) {
            System.out.println("Usage: ComboOfN M N     // M > N and both integers");
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

        try {
            // Build Nums[] array
            BuildNumsArray(N);
            // Calculate Combo of C(N,M)
            CalculateCombo(Nums, M, 0, 0);
            //
            System.out.println("Total " + cnt + " Combos meet requirements.");
        } catch (Exception e) {
            // Handle exception
            System.out.println("\nError:" + e.getLocalizedMessage());
        }
    }
}