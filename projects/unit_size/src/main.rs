use std::mem::size_of_val;

fn main() {
    let unit: () = ();
    // unit type doesn't occupy any memory space
    assert!(size_of_val(&unit) == 0);
}
// Notes:
// Unit size is zero.