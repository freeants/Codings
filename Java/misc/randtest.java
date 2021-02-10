package misc;

import java.util.concurrent.ThreadLocalRandom; // standard way to genrate random number in Java 1.7 and above
import java.util.Scanner;

public class randtest {
    public static void main(String[] args) {
        int Guess;
        int Attempt;
        int MagicNum = ThreadLocalRandom.current().nextInt(0, 101);
        for (Attempt = 0; Attempt < 7; Attempt++) {
            System.out.printf("%d. What's your guess? ", Attempt); // Ask for input
            Guess = new Scanner(System.in).nextInt(); // Scans the next token of the imput as an int

            if (Guess < 0 || Guess > 100) {
                System.out.println("Out of range");
                break;
            }

            if (Guess < MagicNum) {
                System.out.println("Too low, yee scurry dog!");
            } else if (Guess > MagicNum) {
                System.out.println("Too high, yee land lubber!");
            } else {
                System.out.println("Avast! Yee guessed my secret number, yee did!");
                break;
            }
        }
        new Scanner(System.in).close();
        if (Attempt >= 7) {
            System.out.println("Yee out of guesses! Better luck next time, yee matey!");
            System.out.println("My secret number was " + MagicNum);
        }
    }
}