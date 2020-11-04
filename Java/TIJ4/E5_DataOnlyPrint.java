package TIJ4;

//:E5_DataOnlyPrint.java

public class E5_DataOnlyPrint {
    int i;
    double d;
    boolean b;

    public static void main(String[] args) {
        E5_DataOnlyPrint data = new E5_DataOnlyPrint();
        data.i = 47;
        data.d = 1.1;
        data.b = false;
        System.out.println(data.i);
        System.out.println(data.d);
        System.out.println(data.b);
    }
}