package ALGO4;

// gcdApp.java

class gcdApp {
    public static int gcd(int p, int q) {
        if (q == 0)
            return p;
        int r = p % q;
        return gcd(q, r);
    }

    public static void main(String[] args) {
        if (args.length != 2) {
            System.out.println("Usage: gcdApp p, q  # integers");
            return;
        }
        int p = Integer.valueOf(args[0]);
        int q = Integer.valueOf(args[1]);
        System.out.println("gcd(" + p + ", " + q + ") = " + gcd(p, q));
    }
}
