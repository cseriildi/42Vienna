#![forbid(unsafe_op_in_unsafe_fn)]
#![allow(dead_code)]

use std::ptr;

fn ft_swap<T>(a: &mut T, b: &mut T) {
	// SAFETY:
	// the compiler will not let call this function when:
	// a or b are not valid for read and write
	// a or b are unaligned
	// a or b are not initialized
	// a or b are references to the same object
	// a and b are overlapping
	unsafe {
		let tmp = ptr::read(a);
		ptr::write(a, ptr::read(b));
		ptr::write(b, tmp);
	}
}

/// # Safety
/// Ensure that:
/// the pointer is valid and points to a null-terminated string
/// the string is properly null-terminated
/// the string is not longer than `isize::MAX` bytes
unsafe fn ft_strlen(s: *const u8) -> usize {
	let mut len: usize = 0;
	// SAFETY:
	// the user's responsibility to ensure that:
	// the pointer is valid
	// the string is properly null-terminated
	// the string is not longer than `isize::MAX` bytes
	unsafe {
		while *s.add(len) != 0 {
			len += 1;
		}
	}
	len
}

#[allow(dead_code)]
/// # Safety
/// Ensure that:
/// the pointers are valid
/// the src is properly null-terminated
/// the dst has enough space
/// the src is not longer than `isize::MAX` bytes
unsafe fn ft_strcpy(dst: *mut u8, src: *const u8) {
	let mut i = 0;
	// SAFETY:
	// the user's responsibility to ensure that:
	// the pointers are valid
	// the src is properly null-terminated
	// the dst has enough space
	// the src is not longer than `isize::MAX` bytes
	unsafe {
		while *src.add(i) != 0 {
			*dst.add(i) = *src.add(i);
			i += 1;
		}
		*dst.add(i) = 0;
	}
}

#[cfg(test)]
mod tests {
    use super::*;

	#[test]
    fn test_ft_swap() {
        let mut a = String::from("Hello, World!");
        let mut b = String::from("Goodbye, World!");
        ft_swap(&mut a, &mut b);
        assert_eq!(a, "Goodbye, World!");
        assert_eq!(b, "Hello, World!");
    }

    #[test]
    fn test_ft_strlen() {
        let s = b"Hello, World!\0";
        // SAFETY:
        // The pointer `s.as_ptr()` is valid, and the string is null-terminated.
        let len = unsafe { ft_strlen(s.as_ptr()) };
        assert_eq!(len, 13);
    }

    #[test]
    fn test_ft_strcpy() {
        let s = b"Hello, World!\0";
        let mut dst = [0u8; 14];
        // SAFETY:
        // The pointer `s.as_ptr()` is valid and null-terminated, and `dst` has enough space.
        unsafe { ft_strcpy(dst.as_mut_ptr(), s.as_ptr()) };
        assert_eq!(dst, *s);
    }
}