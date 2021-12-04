use std::fs;
use std::io::{BufRead, BufReader};


fn main() {
    let file = match fs::File::open("./input.txt") {
        Ok(file) => file,
        Err(_) => panic!("Unable to open input file"),
    };
    let buffer = BufReader::new(file);
    let mut first_line = String::new();
    let _ = buffer.read_line(&mut first_line);
    let nums: Vec<i32> = get_nums(first_line);
}

fn get_nums(line: String) -> Vec<i32> {

}
