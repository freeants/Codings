package TIJ4;

//:E7_Increamentable.java

//Exercise 7: (1) Turn the Incrementable code fragments into a working program.

class Incrementable {
    static void increment() {
        StaticTest.i++;
    }

    public static void main(final String[] args) {
        new StaticTest();
        new StaticTest();

        StaticTest.i++;
        StaticTest.i++;

        Incrementable.increment();
        System.out.println("st1 = " + StaticTest.i + ", st2 = " + StaticTest.i);
    }
}

class StaticTest {
    static int i = 47;
}