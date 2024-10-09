#[derive(Default, Debug, Clone, PartialEq, PartialOrd)]
struct MyType {}

fn main() {
	let instance = MyType::default();

	let other_instance = instance.clone();

	println!("the default value of MyType is {instance:?}");
	println!("the clone of `instance` is {other_instance:#?}");
	assert_eq!(
		instance,
		other_instance,
		"the clone isn't the same :/"
	);
	assert!(
		instance == other_instance,
		"why would the clone be less or greater than the original?",
	);
}