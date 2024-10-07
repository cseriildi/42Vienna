fn make_overflow(a: u8, b: u8) -> u8 {
	let c: u8 = a + b;
	c
}

fn main() {

	let a: u8 = 255;
	let b: u8 = 1;
	let c: u8 = make_overflow(a, b);

	if c == 0 {
		std::println!("{}u8 + {}u8 == {}", a, b, c);
    }
}