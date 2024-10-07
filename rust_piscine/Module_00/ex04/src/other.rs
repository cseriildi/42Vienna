fn main() {
	std::println!("Hey! I'm the other bin target!");
	#[cfg(not(debug_assertions))]
	std::println!("I'm in release mode!");

}
