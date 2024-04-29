// Convert temperatures between Fahrenheit and Celsius.
// formula C=(5/9)(F-32)

use std::io;

fn main() {
    println!("Convert Fahrenheit to Celsius.");
    loop {
        println!("Input Fahrenheit temperature:");

        let mut far = String::new();

        io::stdin()
            .read_line(&mut far)
            .expect("Failed to read line.");

        let far: f32 = match far.trim().parse() {
            Ok(num) => num,
            Err(_) => {
                println!("None numeric input, quit.");
                break;
            }
        };

        let cel = (5.0 / 9.0) * (far - 32.0);
        println!("It's {cel} degree in Celsius.");
    }
}
