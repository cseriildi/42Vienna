use std::sync::atomic::{AtomicU8, Ordering};

#[allow(dead_code)]
static COUNTER: AtomicU8 = AtomicU8::new(0);

#[derive(Debug, PartialEq, Eq)]

#[allow(dead_code)]

struct Unique(u8);

impl Unique {
	pub fn new() -> Self {
		let id = COUNTER.load(Ordering::SeqCst);

		if id == u8::MAX {
			panic!("No more unique identifiers available!");
		}
		
		COUNTER.fetch_add(1, Ordering::SeqCst);
		Unique(id)
	}
}

impl Clone for Unique {
	fn clone(&self) -> Self {
		Unique::new()
	}
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_unique_identifiers() {
        let a = Unique::new();
        let b = Unique::new();
        let c = Unique::new();

        assert_ne!(a, b);
        assert_ne!(b, c);
        assert_ne!(a, c);

        let d = a.clone();
        let e = c.clone();

        assert_ne!(a, d);
        assert_ne!(c, e);
        assert_ne!(d, e);

    }


    #[test]
    #[should_panic]
    fn test_unique_overflow() {
        for _ in 0..256 {
            Unique::new();
        }

        Unique::new();
    }
}

