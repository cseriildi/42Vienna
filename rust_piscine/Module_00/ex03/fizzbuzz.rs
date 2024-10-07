fn fizzbuzz() {
	for i in 1..101 {
		match (i % 3, i % 5, i % 11) {
			(0, 0, _) => std::println!("fizzbuzz"),
			(0, _, _) => std::println!("fizz"),
			(_, 0, _) => std::println!("buzz"),
			(_, _, 3) => std::println!("FIZZ"),
			(_, _, 5 ) => std::println!("BUZZ"),
			_ => std::println!("{i}")
		}
	}
}

fn main() {
	fizzbuzz();
}