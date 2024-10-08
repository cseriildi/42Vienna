#[allow(dead_code)]
fn big_add(a: &[u8], b: &[u8]) -> Vec<u8> {
	if a.is_empty() || b.is_empty() {
		panic!("empty list")
	}
	for ch in a {
		if !ch.is_ascii_digit() {
			panic!("{} is not a digit", ch);
		}
	}
	for ch in b {
		if !ch.is_ascii_digit() {
			panic!("{} is not a digit", ch);
		}
	}
	
	let mut len_a = a.len();
	let mut len_b = b.len();
	let mut remainder: u8 = 0;
	let mut reverse_vec: Vec<u8> = Vec::new();
	let mut result: Vec<u8> = Vec::new();
	let mut value;

	while len_a >= 1 && len_b >= 1 {
		len_a -= 1;
		len_b -= 1;
		value = a[len_a] - b'0' + b[len_b] - b'0' + remainder;
		remainder = value / 10;
		reverse_vec.push(value % 10 + b'0');
	}

	while len_a >= 1 {
		len_a -= 1;
		value = a[len_a] - b'0' + remainder;
		remainder = value / 10;
		reverse_vec.push(value % 10 + b'0');
	}

	while len_b >= 1 {
		len_b -= 1;
		value = b[len_b] - b'0' + remainder;
		remainder = value / 10;
		reverse_vec.push(value % 10 + b'0');
	}
	if remainder == 1 {
		reverse_vec.push(remainder + b'0');
	}
	let mut vec_size: usize = reverse_vec.len();
	while vec_size >= 2  && reverse_vec[vec_size - 1] == b'0' {
		vec_size -= 1;
	}
	while vec_size >= 1 {
		vec_size -= 1;
		result.push(reverse_vec[vec_size]);
	}
	result
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        assert_eq!(big_add(b"2", b"4"), b"6");
    }

    #[test]
    fn test_large_numbers() {
        assert_eq!(big_add(b"999", b"1"), b"1000");
    }

    #[test]
    fn test_different_lengths() {
        assert_eq!(big_add(b"123", b"7890"), b"8013");
    }

    #[test]
    fn test_with_carry() {
        assert_eq!(big_add(b"9999", b"1"), b"10000");
    }

    #[test]
    fn test_trailing_zeros() {
        assert_eq!(big_add(b"1000", b"1000"), b"2000");
    }

    #[test]
    fn test_zero_case() {
        assert_eq!(big_add(b"0", b"12345"), b"12345");
    }

    #[test]
    fn test_carry_multiple_digits() {
        assert_eq!(big_add(b"999999", b"1"), b"1000000");
    }

    #[test]
    fn test_leading_zeros_same_length() {
        assert_eq!(big_add(b"00123", b"00077"), b"200");
    }

    #[test]
    fn test_leading_zeros_different_lengths() {
        assert_eq!(big_add(b"000123", b"045"), b"168");
    }

    #[test]
    fn test_leading_zeros_large_number() {
        assert_eq!(big_add(b"00000001", b"99999999"), b"100000000");
    }

    #[test]
    #[should_panic(expected = "empty list")]
    fn test_panic_empty_list() {
        big_add(b"", b"12345");
    }

    #[test]
    #[should_panic(expected = "is not a digit")]
    fn test_panic_invalid_input() {
        big_add(b"12a", b"345");
    }
}
