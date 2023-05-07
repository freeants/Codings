package misc;

public class ColourConsoleDemo {
    /**
     *
     * @param args
     *
     *             "\033[0m BLACK" will colour the whole line
     *
     *             "\033[37m WHITE\033[0m" will colour only WHITE. For colour while
     *             Opening --> "\033[37m" and closing --> "\033[0m"
     *
     *
     */
    public static void main(String[] args) {
        // printing words in their respective color
        System.out.println("\033[0m BLACK");
        System.out.println("\033[31m RED");
        System.out.println("\033[32m GREEN");
        System.out.println("\033[33m YELLOW");
        System.out.println("\033[34m BLUE");
        System.out.println("\033[35m MAGENTA");
        System.out.println("\033[36m CYAN");
        System.out.println("\033[37m WHITE\033[0m");

        // printing the results
        String leftAlignFormat = "| %-20s | %-7d | %-7d | %-7d |%n";

        System.out.format("|---------Test Cases with Steps Summary -------------|%n");
        System.out.format("+----------------------+---------+---------+---------+%n");
        System.out.format("| Test Cases           |Passed   |Failed   |Skipped  |%n");
        System.out.format("+----------------------+---------+---------+---------+%n");

        String formattedMessage = "TEST_01".trim();

        leftAlignFormat = "| %-20s | %-7d | %-7d | %-7d |%n";
        System.out.print("\033[31m"); // Open print red
        System.out.printf(leftAlignFormat, formattedMessage, 2, 1, 0);
        System.out.print("\033[0m"); // Close print red
        System.out.format("+----------------------+---------+---------+---------+%n");
    }
}