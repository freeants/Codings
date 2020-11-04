package TIJ4;

//:E6_RetStorage.java

public class E6_RetStorage {

    static int storage(String s) {
        return s.length() * 2;
    }

    public static void main(String[] args) {
        String s = "Hello, World!";
        // print the length
        System.out.println("The storage space of " + s + " is " + storage(s));
    }
}