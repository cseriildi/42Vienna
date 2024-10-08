#[allow(dead_code)]
fn ft_contains(list: &[i32], num: &i32) -> bool {
	for element in list {
		if element == num {
			return true
		}
	}
	false
}

#[allow(dead_code)]
fn deduplicate(list: &mut Vec<i32>) {

	let mut count: usize = list.len();
	let mut index: usize = 0;

	while index < count {
		if ft_contains(&list[0..index], &list[index]) {
			list.remove(index);
			count -= 1;
		}
		else {
			index += 1;
		}
	}
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let mut v = vec![1, 2, 2, 3, 2, 4, 3];
        deduplicate(&mut v);
        assert_eq!(v, vec![1, 2, 3, 4]);
    }

    #[test]
    fn test_no_duplicates() {
        let mut v = vec![1, 2, 3, 4];
        deduplicate(&mut v);
        assert_eq!(v, vec![1, 2, 3, 4]);
    }

    #[test]
    fn test_all_duplicates() {
        let mut v = vec![1, 1, 1, 1];
        deduplicate(&mut v);
        assert_eq!(v, vec![1]);
    }

    #[test]
    fn test_empty_list() {
        let mut v: Vec<i32> = vec![];
        deduplicate(&mut v);
        assert!(v.is_empty());
    }

    #[test]
    fn test_single_element() {
        let mut v = vec![1];
        deduplicate(&mut v);
        assert_eq!(v, vec![1]);
    }

    #[test]
    fn test_two_identical_elements() {
        let mut v = vec![1, 1];
        deduplicate(&mut v);
        assert_eq!(v, vec![1]);
    }

    #[test]
    fn test_alternating_duplicates() {
        let mut v = vec![1, 2, 1, 2, 1];
        deduplicate(&mut v);
        assert_eq!(v, vec![1, 2]);
    }

    #[test]
    fn test_large_list_with_duplicates() {
        let mut v = vec![1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 6, 7, 8];
        deduplicate(&mut v);
        assert_eq!(v, vec![1, 2, 3, 4, 5, 6, 7, 8]);
    }
}

