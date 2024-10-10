use std::fmt::Debug;

trait FortyTwo {
    fn forty_two() -> Self;
}

impl FortyTwo for i32 {
	fn forty_two() -> Self {
		let instance: i32 = 42;
		instance
	}
}

impl FortyTwo for String {
	fn forty_two() -> Self {
		String::from("fortytwo")
	}
}

fn print_forty_two<T: Debug + FortyTwo>() {

	let instance: T = FortyTwo::forty_two(); 
	println!("{:?}", instance);
}


fn main() {
	print_forty_two::<i32>();
	print_forty_two::<String>();
}
