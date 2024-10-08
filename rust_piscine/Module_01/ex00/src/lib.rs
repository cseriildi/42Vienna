pub fn add(a: &i32, b: i32) -> i32 {
	a + b
}

#[allow(dead_code)]
fn add_assign(a: &mut i32, b: i32) {
	*a = add(a, b);
}

#[cfg(test)]
mod tests {
	use super::*;

	#[test]
	fn test_add() {
		let result = add(&2, 2);
		assert_eq!(result, 4);
	}
	#[test]
	fn test_add_assign() {
		let mut a: i32 = 2;
		add_assign(&mut a, 2);
		assert_eq!(a, 4);
	}
}
