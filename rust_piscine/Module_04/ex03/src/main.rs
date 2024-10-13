use std::io::{self, BufRead};
use std::process::Command;

fn main() -> Result<(),io::Error> {
	let mut args: Vec<String> = std::env::args().collect();
	args.remove(0);
	let mut input:Vec<String> = Vec::new();
	let mut line: String = String::new();

	while io::stdin().lock().read_line( &mut line)? != 0 {
		input.push(String::from(line.trim_end_matches('\n')));
		line.clear();
	}
	args.append(&mut input);

	if !args.is_empty() {
		let _ = Command::new(args.remove(0))
			.args(&args)
			.spawn();
	}
	Ok(())
}
