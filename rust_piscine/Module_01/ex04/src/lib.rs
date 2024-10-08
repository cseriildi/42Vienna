#[allow(dead_code)]
fn can_fit(a :&[u32; 2], b: &[u32; 2]) -> bool {
	b[0] <= a[0] && b[1] <= a[1]
}

#[allow(dead_code)]
fn sort_boxes(boxes: &mut [[u32; 2]]) {
	if boxes.is_empty() { return }

	let count: usize = boxes.len();

	for i in 0..count - 1 {
		for j in 0..count - 1 - i {
			if !can_fit(&boxes[j], &boxes[j + 1]) {
				boxes.swap(j, j + 1);
			}
		}
	}

	for i in 0.. count -1 {
		if !can_fit(&boxes[i], &boxes[i + 1]) {
			panic!("Can not be sorted!")
		}
	}
}



#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let mut boxes = [[3, 3], [4, 3], [1, 0], [5, 7], [3, 3]];
        sort_boxes(&mut boxes);
        assert_eq!(boxes, [[5, 7], [4, 3], [3, 3], [3, 3], [1, 0]]);
    }

	#[test]
    #[should_panic]
    fn test_panic() {
        let mut boxes = [[10, 1], [1, 10], [1, 1]];
        sort_boxes(&mut boxes);
    }
	
    #[test]
    fn test_empty_boxes() {
        let mut boxes: [[u32; 2]; 0] = [];
		let empty: [[u32; 2]; 0] = [];
        sort_boxes(&mut boxes);
        assert_eq!(boxes, empty);
    }

    #[test]
    fn test_no_fit() {
        let mut boxes = [[1, 1], [2, 2], [3, 3]];
        sort_boxes(&mut boxes);
        assert_eq!(boxes, [[3, 3], [2, 2], [1, 1]]);
    }


    #[test]
    fn test_identical_boxes() {
        let mut boxes = [[3, 3], [3, 3], [3, 3]];
        sort_boxes(&mut boxes);
        assert_eq!(boxes, [[3, 3], [3, 3], [3, 3]]);
    }

    #[test]
    fn test_large_boxes() {
        let mut boxes = [[10, 10], [8, 8], [12, 12]];
        sort_boxes(&mut boxes);
        assert_eq!(boxes, [[12, 12], [10, 10], [8, 8]]);
    }

    #[test]
    fn test_small_boxes() {
        let mut boxes = [[1, 1], [0, 0], [2, 2]];
        sort_boxes(&mut boxes);
        assert_eq!(boxes, [[2, 2], [1, 1], [0, 0]]);
    }

    #[test]
    fn test_sorted_boxes() {
        let mut boxes = [[1, 2], [2, 3], [3, 4]];
        sort_boxes(&mut boxes);
        assert_eq!(boxes, [[3, 4], [2, 3], [1, 2]]);
    }

    #[test]
    fn test_unsorted_boxes_with_no_fit() {
        let mut boxes = [[4, 4], [2, 2], [1, 1], [3, 3]];
        sort_boxes(&mut boxes);
        assert_eq!(boxes, [[4, 4], [3, 3], [2, 2], [1, 1]]);
    }

    #[test]
    fn test_mixed_fit() {
        let mut boxes = [[4, 4], [3, 3], [5, 5], [2, 2]];
        sort_boxes(&mut boxes);
        assert_eq!(boxes, [[5, 5], [4, 4], [3, 3], [2, 2]]);
    }

    #[test]
    fn test_fit_with_large_box() {
        let mut boxes = [[100, 100], [50, 50], [30, 30], [80, 80]];
        sort_boxes(&mut boxes);
        assert_eq!(boxes, [[100, 100], [80, 80], [50, 50], [30, 30]]);
    }

    #[test]
    fn test_single_box() {
        let mut boxes = [[1, 1]];
        sort_boxes(&mut boxes);
        assert_eq!(boxes, [[1, 1]]);
    }

    #[test]
    fn test_two_identical_boxes() {
        let mut boxes = [[2, 2], [2, 2]];
        sort_boxes(&mut boxes);
        assert_eq!(boxes, [[2, 2], [2, 2]]);
    }
}
