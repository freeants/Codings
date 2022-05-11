// control/WhileTest.java
// Demonstrates the while loop
public class WhileTest {
	static long cnt = 0;
	static boolean condition() {
		boolean result = Math.random() < 0.99;
		System.out.print(result + ", ");
		return result;
	}
	public static void main(String[] args) {
		while (condition())
			System.out.println("Inside 'while' (" + (++cnt) + ")");
		System.out.println("Exited 'while'");
	}
}
/* Output: (First and Last 5 Lines)
true, Inside 'while'
true, Inside 'while'
true, Inside 'while'
true, Inside 'while'
true, Inside 'while'
...________...________...________...________...
true, Inside 'while'
true, Inside 'while'
true, Inside 'while'
true, Inside 'while'
false, Exited 'while'
*/