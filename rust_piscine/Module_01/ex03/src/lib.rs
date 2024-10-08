#[allow(dead_code)]
fn largest_group<'a>(haystack: &'a [u32], needle: &[u32]) -> &'a [u32] {
	if haystack.is_empty() || needle.is_empty() { return &[] }
	let mut possible_slice_size:usize = 0;
	let mut max_slice_size:usize = 0;
	let mut max_start:usize = 0;
	let h_len: usize = haystack.len();
	let n_len: usize = needle.len();

	for i in 0..=h_len {
		if i != h_len && needle.contains(&haystack[i]) {
			possible_slice_size += 1;
		}
		else if possible_slice_size != 0 {
			let possible_slice = &haystack[i - possible_slice_size..i];
			let mut j = 0;
			while j < n_len && possible_slice.contains(&needle[j]) {
				j += 1;
			}
			if j == n_len && possible_slice_size > max_slice_size {
				max_slice_size = possible_slice_size;
				max_start = i - max_slice_size;

			}
			possible_slice_size = 0;
		}
	}
	&haystack[max_start..max_start + max_slice_size]
	
}
#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_largest_group() {
        let haystack = [1, 2, 3, 2, 1];
        let needle = [2, 3];
        let result = largest_group(&haystack, &needle);
        assert_eq!(result, &[2, 3, 2]);
    }

    #[test]
    fn test_no_matches() {
        let haystack = [4, 5, 6];
        let needle = [1, 2, 3];
        let result = largest_group(&haystack, &needle);
        assert_eq!(result, &[]);
    }

    #[test]
    fn test_single_element_match() {
        let haystack = [1, 2, 3, 4, 5];
        let needle = [3];
        let result = largest_group(&haystack, &needle);
        assert_eq!(result, &[3]);
    }

    #[test]
    fn test_multiple_groups() {
        let haystack = [1, 2, 3, 2, 1, 3, 4, 5, 6];
        let needle = [2, 3];
        let result = largest_group(&haystack, &needle);
        assert_eq!(result, &[2, 3, 2]);
    }

    #[test]
    fn test_needle_empty() {
        let haystack = [1, 2, 3];
        let needle: [u32; 0] = [];
        let result = largest_group(&haystack, &needle);
        assert_eq!(result, &[]);
    }

    #[test]
    fn test_haystack_empty() {
        let haystack: [u32; 0] = [];
        let needle = [1, 2];
        let result = largest_group(&haystack, &needle);
        assert_eq!(result, &[]);
    }

    #[test]
    fn test_overlapping_groups() {
        let haystack = [1, 2, 3, 2, 2, 3, 1, 2, 3];
        let needle = [2, 3];
        let result = largest_group(&haystack, &needle);
        assert_eq!(result, &[2, 3, 2, 2, 3]);
    }

    #[test]
    fn test_all_elements_in_needle() {
        let haystack = [2, 3, 2, 3, 2, 3];
        let needle = [2, 3];
        let result = largest_group(&haystack, &needle);
        assert_eq!(result, &[2, 3, 2, 3, 2, 3]);
    }

    #[test]
    fn test_single_element_haystack() {
        let haystack = [3];
        let needle = [3];
        let result = largest_group(&haystack, &needle);
        assert_eq!(result, &[3]);
    }

    #[test]
    fn test_multiple_identical_elements() {
        let haystack = [2, 2, 2, 2, 3, 2, 3, 2];
        let needle = [2, 3];
        let result = largest_group(&haystack, &needle);
        assert_eq!(result, &[2, 2, 2, 2, 3, 2, 3, 2]);
    }

    #[test]
    fn test_contiguous_groups() {
        let haystack = [1, 2, 2, 3, 3, 1, 2, 3];
        let needle = [2, 3];
        let result = largest_group(&haystack, &needle);
        assert_eq!(result, &[2, 2, 3, 3]);
    }

    #[test]
    fn test_needle_with_non_matching_elements() {
        let haystack = [5, 6, 1, 2, 3];
        let needle = [7, 8];
        let result = largest_group(&haystack, &needle);
        assert_eq!(result, &[]);
    }

    #[test]
    fn test_assertions() {
        assert_eq!(largest_group(&[1, 3, 4, 3, 5, 5, 4], &[5, 3]), &[3, 5, 5]);
        assert_eq!(largest_group(&[1, 3, 4, 3, 5, 5, 4], &[5]), &[5, 5]);
        assert_eq!(largest_group(&[1, 3, 4, 3, 5, 5, 4], &[]), &[]);
        assert_eq!(largest_group(&[1, 3, 4, 3, 5, 5, 4], &[4, 1]), &[]);
    }
}
