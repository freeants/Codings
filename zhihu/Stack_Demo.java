import java.util.*;

public class Stack_Demo {
    public static void main(String[] args) {

        // Creating an empty Stack
        Stack<Integer> stack = new Stack<Integer>();
        int sum = 0;
        // Inserting elements into the table
        stack.add(10);
        stack.add(15);
        stack.add(20);
        stack.add(25);
        stack.add(30);

        // Displaying the Stack
        System.out.println("The Stack is: " + stack);

        // Creating an empty enumeration to store
        Enumeration<Integer> enu = stack.elements();

        System.out.println("The enumeration of values are:");

        // Displaying the Enumeration
        while (enu.hasMoreElements()) {
            //System.out.println(enu.nextElement()+1);
            sum += enu.nextElement();
        }
        System.out.println(sum);
    }
}