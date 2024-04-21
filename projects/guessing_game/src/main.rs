use rand::Rng;
use std::cmp::Ordering;
use std::io;

fn main() {
    println!("I have a secret number between 1..100, guess it with minimal tries.");

    let secret_number = rand::thread_rng().gen_range(1..=100);
    let mut tries = 0;

    loop {
        tries = tries + 1;
        println!("{tries}. Input your guess.");

        let mut guess = String::new();

        io::stdin()
            .read_line(&mut guess)
            .expect("Failed to read line");

        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };

        println!("You guessed: {guess}");

        match guess.cmp(&secret_number) {
            Ordering::Less => println!("Too small!"),
            Ordering::Greater => println!("Too big!"),
            Ordering::Equal => {
                println!("You win! The secret number is {secret_number}, you tried {tries} times.");
                break;
            }
        }
    }
}
