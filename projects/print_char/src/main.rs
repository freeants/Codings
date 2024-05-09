// 修改一行让代码正常打印
fn main() {
    let c1 = '中';
    print_char(c1);
}

fn print_char(c: char) {
    println!("{}", c);
}

// Notes:
// "char" type var is in single '', "str" type is in double "".
