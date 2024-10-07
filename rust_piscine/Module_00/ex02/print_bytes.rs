fn print_bytes(s: &str) {
	for byte in str::bytes(s) {
		std::println!("{byte}");
	}
}

/* fn main() {
	let mut str = "Déjà Vu\n";
	std::println!("Print bytes of [{str}]");
	print_bytes(str);

	str = "";
	std::println!("Print bytes of [{str}]");
	print_bytes(str);
} */