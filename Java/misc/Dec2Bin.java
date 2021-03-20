

/**
 * This converts input DEC integers into HEX, OCT and BIN based formats.
 */

class Dec2Bin {
    static Integer decimal;

    public static boolean isInteger(final String s) {
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

    public static void main(final String[] args) {
        if (args.length != 1) {
            System.out.println("\033[34mUsage: " + "\033[37m Dec2Bin n\033[0m");
            return;
        }

        if (isInteger(args[0])) {
            decimal = Integer.valueOf(args[0]);
            System.out.printf("HEX " + "%x%n", decimal);
            System.out.printf("DEC " + "%,d%n", decimal);
            System.out.printf("OCT " + "%o%n", decimal);
            System.out.printf("BIN " + Integer.toBinaryString(decimal));
        } else {
            System.out.println("Input integers only");
        }
    }
}
