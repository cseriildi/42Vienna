use ftkit::random_number;

fn choose<T>(values: &[T]) -> &T {
	let max = values.len() as i32;
	let value = random_number(0..max) as usize;
	&values[value]
}

fn main() {
	let values = vec![1, 2, 3, 4, 5];
	let value = choose(&values);
	println!("Value: {value}");
}