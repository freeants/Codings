package misc;

import java.util.Arrays;
import java.util.Scanner;
import java.util.Vector;

public class test {
    static int cnt = 0;

    public static void main(String[] args) {
        Vector<Integer> v = new Vector<>();
        for (int i = 0; i <= 9; i++)
            v.add(i);
        System.out.print("Input selection number: ");
        Scanner input = new Scanner(System.in);
        int k = input.nextInt();
        int[] solution = new int[k];
        System.out.println(
                Combination(v, solution, 0, 0) + " solutions in total and " + cnt + " combos meet requirements.");
        input.close();
    }
   
    static void conditions(int[] solution) {
        int sum = 0;
        boolean c = false;
        for (int i = 0; i < solution.length; i++) {
            sum += solution[i];
            if (solution[i] >= 5) {
                c = true;
            }
        }
        if ((sum == 10) && c) {
            System.out.println(++cnt + ":" + Arrays.toString(solution));
        }

    }

    public static int Combination(Vector<Integer> v, int[] solution, int start, int pos) {
        if ((pos == solution.length)) {
            //
            conditions(solution);
            return 1;
        }

        int count = 0;
        for (int i = start; i < v.size(); i++) {
            solution[pos++] = v.get(i);
            count += Combination(v, solution, i + 1, pos);
            pos--;
        }

        return count;
    }
}