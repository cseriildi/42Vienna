use std::io::Write;
	
fn main() {
	for i in 1..=10 {
		let _ = writeln!(std::io::stdout(), "{i}");
	}
}
