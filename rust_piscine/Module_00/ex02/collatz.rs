fn collatz(start: u32) {
	let mut n: u32 = start;

	if n != 0 {
		while n != 1 {
			std::println!("{}", n);
			match n % 2 {
				0 => n/= 2,
				_ => n = n * 3 + 1
			}
		}
		std::println!("{n}");
	}
}

/* fn main() {
	let mut start: u32 = 42;
	println!("Collatz for {start}:");
	collatz(start);

	start = 0;
	std::println!("Collatz for {start}:");
	collatz(start);
} */
