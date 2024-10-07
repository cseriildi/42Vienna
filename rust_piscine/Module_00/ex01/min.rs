fn min(a: i32, b: i32) -> i32 {
	if a < b {a} else {b}
}

fn main() {
	let a: i32 = 24;
	let b: i32 = 42; 
	std::println!("min({}, {}) is {}", a, b, min(a, b));
	std::println!("min({}, {}) is {}", -a, b, min(-a, b));
	std::println!("min({}, {}) is {}", a, -b, min(a, -b));
	std::println!("min({}, {}) is {}", 0, b, min(0, b));
	std::println!("min({}, {}) is {}", 0, -b, min(0, -b));
}