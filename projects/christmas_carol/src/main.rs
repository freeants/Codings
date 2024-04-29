//Print the lyrics to the Christmas carol “The Twelve Days of Christmas,”
//taking advantage of the repetition in the song.

fn main() {
    let days = [
        "first", "second", "third", "fourth", "fifth", "sixth", "seventh", "eighth", "ninth",
        "tenth", "eleventh", "twelfth",
    ];
    let gifts = [
        "a partridge in a pear tree",
        "two turtle doves",
        "three French hens",
        "four calling birds",
        "five gold rings",
        "six geese a-laying",
        "seven swans a-swimming",
        "eight maids a-milking",
        "nine ladies dancing",
        "ten lords a-leaping",
        "eleven pipers piping",
        "twelve drummers drumming",
    ];

    println!("The Twelve Days of Christmas\n");

    for day in 0..days.len() {
        println!(
            "On the {} day of Christmas, my true love sent to me:",
            days[day]
        );
        for gift in (0..=day).rev() {
            if gift == 0 && day != 0 {
                print!("and ");
            }
            println!("{}", gifts[gift]);
        }
        println!();
    }
}
