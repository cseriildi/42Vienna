use std::cmp::Ordering;

fn main() {
	let mut guess: i32;
	let rand_num: i32 = ftkit::random_number(0..=100);
	std::println!("Me and my infinite wisdom have found an appropriate secret you shall yearn for.");
	
	loop {
		guess = ftkit::read_number();
		match guess.cmp(&rand_num) {
			Ordering::Less => println!("This student might not be as smart as I was told. This answer is obviously too weak."),
			Ordering::Greater => println!("Sometimes I wonder whether I should retire. I would have guessed higher."),
			Ordering::Equal => {
				println!("That is right! The secret was indeed the number {guess}, which you have brilliantly discovered!");
				break
			}
		}
	}
}
