fn main() {
    never_return();
}

use std::thread;
use std::time;

fn never_return() -> ! {
    // implement this function, don't modify fn signatures
    loop {
        println!("I return nothing");
        // sleeping for 1 second to avoid exhausting the cpu resource
        thread::sleep(time::Duration::from_secs(1))
    }
   //panic!("I return nothing")
}
// Notes:
// Above is method one the implement ! ruturn type. Another method is to use panic!() or unimplemented!() or todo!(); to replace the loop statment block:
// panic!("I return nothing")