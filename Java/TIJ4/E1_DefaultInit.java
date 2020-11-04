package TIJ4;

//: E1_DefaultInit.java

//Exercise 1: (2) Create a class containing an int and a char that are not initialized, 
//and print their values to verify that Java performs default initialization.

public class E1_DefaultInit {
    int i;
    char c;

    public E1_DefaultInit() {
        System.out.println("i = " + i);
        System.out.println("c = " + c);
    }
    public static void main(final String args[]) {
        new E1_DefaultInit();
    }
}