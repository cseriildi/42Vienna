pub fn min<'c>(a: &'c i32, b: &'c i32) -> &'c i32 {
	if a < b {a} else {b}

}

#[cfg(test)]
mod tests {
	use super::*;

	#[test]
	fn test_min1() {
		let a: i32 = 24;
		let b: i32 = 42;
		let c = min(&a, &b);
		assert_eq!(c, &a);
	}
	#[test]
	fn test_min2() {
		let result = min(&0, &42);
		assert_eq!(result, &0);
	}
	#[test]
	fn test_min3() {
		let result = min(&42, &-42);
		assert_eq!(result, &-42);
	}
	#[test]
	fn test_min4() {
		let result = min(&0, &0);
		assert_eq!(result, &0);
	}

}
