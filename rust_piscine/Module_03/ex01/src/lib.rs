#![allow(dead_code)]
fn min<T: Sized + PartialOrd>(a: T, b: T) -> T {
	if a < b { a } else { b }
}

#[cfg(test)]
mod tests {
	use super::*;

	#[test]
	fn test_min_with_bool() {
		assert_eq!(min(true, false), false);
	}

	#[test]
	fn test_min_with_integers() {
		assert_eq!(min(42, 24), 24);
	}

	#[test]
	fn test_min_with_floats() {
		assert_eq!(min(4.5, 2.3), 2.3);
	}

	#[test]
	fn test_min_with_strings() {
		assert_eq!(min(String::from("apple"), String::from("banana")), "apple");
	}

	#[test]
	fn test_min_with_chars() {
		assert_eq!(min('a', 'z'), 'a');
	}

	#[test]
	fn test_min_with_i32() {
		assert_eq!(min(12i32, -14i32), -14);
	}

	#[test]
	fn test_min_with_f32() {
		assert_eq!(min(12f32, 14f32), 12f32);
	}

	#[test]
	fn test_min_with_str_slices() {
		assert_eq!(min("abc", "def"), "abc");
	}

	#[test]
	fn test_min_with_strings_borrowed() {
		assert_eq!(min(String::from("abc"), String::from("def")), "abc");
	}
}
