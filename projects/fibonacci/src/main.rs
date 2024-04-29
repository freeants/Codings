//Generate the nth Fibonacci number.
use std::io;

fn fib(mut value: u32) -> u32 {
    let mut a = 0;
    let mut b = 1;

    while value > 0 {
        let sum: u32 = (a + b) % 1000000007;
        a = b;
        b = sum;
        value -= 1;
    }
    return a;
}

fn main() {
    println!("Generate the nth Fibonacci number.");

    loop {
        println!("Input n:");

        let mut n = String::new();

        io::stdin().read_line(&mut n).expect("Failed to read line.");

        let n: u32 = match n.trim().parse() {
            Ok(num) => num,
            Err(_) => {
                println!("None natural number input, quit.");
                break;
            }
        };

        println!("The {n}th Fibonacci number is: {}", fib(n));
    }
}
