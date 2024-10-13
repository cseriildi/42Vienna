use std::cell::Cell;

#[allow(dead_code)]
fn swap_u32(a: &Cell<u32>, b: &Cell<u32>) {
	a.swap(b);
}

#[allow(dead_code)]
fn swap_string(a: &Cell<String>, b: &Cell<String>) {
	a.swap(b);
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_swap_u32() {
        let a = Cell::new(1);
        let b = Cell::new(3);

        swap_u32(&a, &b);

        assert_eq!(a.get(), 3);
        assert_eq!(b.get(), 1);
    }

    #[test]
    fn test_swap_string() {
        let a = Cell::new("ABC".into());
        let b = Cell::new("DEF".into());

        swap_string(&a, &b);

        assert_eq!(a.into_inner(), "DEF");
        assert_eq!(b.into_inner(), "ABC");
    }
}