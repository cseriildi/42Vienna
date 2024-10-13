#![forbid(unsafe_op_in_unsafe_fn)]
#![allow(dead_code)]

use std::mem::transmute;
use std::slice::from_raw_parts;

type GoldNugget = u16;
type Iron = u32;
type Mercure = u64;
type Gold = [GoldNugget];

/// # Safety
/// Ensure that:
/// size is not longer than `isize::MAX` bytes
unsafe trait Metal {}

/// # Safety
/// size is not longer than `isize::MAX` bytes
unsafe impl Metal for GoldNugget {}

/// # Safety
/// size is not longer than `isize::MAX` bytes
unsafe impl Metal for Iron {}

/// # Safety
/// size is not longer than `isize::MAX` bytes
unsafe impl Metal for Mercure {}

/// # Safety
/// size is not longer than `isize::MAX` bytes
unsafe impl Metal for Gold {}

struct PhilosopherStone;

impl PhilosopherStone {
    fn transmute_iron(self, iron: Iron) -> [GoldNugget; 2] {
		// SAFETY:
		// the types have the same size
		unsafe { transmute::<Iron, [GoldNugget; 2]>(iron) }
	}

    fn transmute_mercure(self, mercure: Mercure) -> [GoldNugget; 4] {
		// SAFETY:
		// the types have the same size
		unsafe { transmute::<Mercure, [GoldNugget; 4]>(mercure) }
	}

	fn transmute_metal<M: Metal>(self, metal: &M) -> &Gold {
		
		let len = size_of::<M>() / size_of::<GoldNugget>();
		// SAFETY:
		// metal is a valid reference to a Metal
		// the metal points to len consecutive properly initialized values
		// the total size of the metal is not longer than isize::MAX bytes
		unsafe { from_raw_parts(metal as *const M as *const GoldNugget, len) }
	}
}

#[cfg(test)]
mod tests {
    use super::*;

    struct MyMetal(u64);
	// SAFETY:
	// the type has the same size as the trait object
    unsafe impl Metal for MyMetal {}

    #[test]
    fn test_transmute_iron() {
        let stone = PhilosopherStone;
        let iron: Iron = 0x12345678;
        let gold = stone.transmute_iron(iron);
        assert_eq!(gold, [0x5678, 0x1234]);
    }

    #[test]
    fn test_transmute_mercure() {
        let stone = PhilosopherStone;
        let mercure: Mercure = 0x0123456789ABCDEF;
        let gold = stone.transmute_mercure(mercure);
        assert_eq!(gold, [0xCDEF, 0x89AB, 0x4567, 0x0123]);
    }

    #[test]
    fn test_transmute_metal() {
        let stone = PhilosopherStone;
        let my_metal = MyMetal(0x0123456789ABCDEF);
        let gold = stone.transmute_metal(&my_metal);
        assert_eq!(gold, &[0xCDEF, 0x89AB, 0x4567, 0x0123]);
    }

    #[test]
    fn test_transmute_metal_different_size() {
        struct AnotherMetal(u16, u16, u16);
		// SAFETY:
		// the type has the same size as the trait object
        unsafe impl Metal for AnotherMetal {}

        let stone = PhilosopherStone;
        let another_metal = AnotherMetal(0x1111, 0x2222, 0x3333);
        let gold = stone.transmute_metal(&another_metal);
        assert_eq!(gold, &[0x1111, 0x2222, 0x3333]);
    }
}