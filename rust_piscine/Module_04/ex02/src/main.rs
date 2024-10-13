use std::{fs, io};
use std::path::Path;

fn rec_used_mem_calc(size:&mut u64, p: &Path) -> Result<(),io::Error> {

	for entry in p.read_dir()? {
		let element = entry?;
		let meta = element.metadata()?;
		if  meta.is_file(){
			*size += meta.len();
		}
		else if meta.is_dir() {
			let _ = rec_used_mem_calc(size, element.path().as_path());
		}
		else {
			continue;
		}
	}
	Ok(())
}


fn main() -> Result<(),io::Error> {
	let mut size:u64 = 0;

	if let Some(arg) = std::env::args().nth(1) {
		let p = Path::new(&arg);
	
		let info = fs::metadata(p)?;
		if info.is_dir() {
			let _ = rec_used_mem_calc(&mut size, p);
		}
		else {
			size += info.len();
		}
		match size {
			0..1000 => println!("{size} bytes"),
			1000..1000000 => println!("{}.{} kilobytes", size/1000, size % 1000/100),
			1000000..1000000000 => println!("{}.{} megabytes", size/1000000, size % 1000000/100000),
			_ => println!("{}.{} gigabytes", size/1000000000, size % 1000000000/100000000),
		}
	}
	Ok(())
}