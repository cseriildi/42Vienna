use std::io::{self, Read, Write};
use std::fs::File;

fn main() {
	let mut args: Vec<String> = std::env::args().collect();
	args.remove(0);
	let mut input:Vec<u8> = Vec::new();

	if let Err(e) = io::stdin().lock().read_to_end( &mut input) {
		eprintln!("Error reading from stdin: {e}");
        return;
	}
	if let Err(e) = io::stdout().lock().write_all(&input) {
		eprintln!("Error writing to stdout: {e}");
		return;
	}		
	for filename in args {
		match File::create(filename) {
			Err(e) => eprintln!("Error while creating file {e}"),
			Ok(mut file) => {
				if let Err(e) = file.write_all(&input) {
					eprintln!("Error while writing into file {e}");
				}
			}
		}
	}
}
