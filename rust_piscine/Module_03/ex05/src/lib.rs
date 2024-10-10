use std::ops::{Add, Sub, AddAssign, SubAssign, Mul, MulAssign, Div, DivAssign};

#[derive(Debug, Clone)]
struct Vector<T> {
    x: T,
    y: T
}
#[allow(dead_code)]
impl<T> Vector<T> {
    fn new(x: T, y: T) -> Self {
		Vector {
			x,
			y
		}
	}
}

impl<T: Copy> Copy for Vector<T> {}

impl<T> Add for Vector<T>
where
T: Add<Output = T>,
{
    type Output = Vector<T>;

    fn add(self, other: Vector<T>) -> Vector<T> {
        Vector {
            x: self.x + other.x,
            y: self.y + other.y,
        }
    }
}

impl<T> AddAssign for Vector<T>
where
T: AddAssign,
{
	fn add_assign(&mut self, other: Vector<T>) {
			self.x += other.x;
			self.y += other.y;
	}
}

impl<T> Sub for Vector<T>
where
T: Sub<Output = T>,
{
    type Output = Vector<T>;

    fn sub(self, other: Vector<T>) -> Vector<T> {
        Vector {
            x: self.x - other.x,
            y: self.y - other.y,
        }
    }
}

impl<T> SubAssign for Vector<T>
where
T: SubAssign,
{
    fn sub_assign(&mut self, other: Vector<T>) {
        self.x -= other.x;
        self.y -= other.y;
    }
}

impl<T> Mul<T> for Vector<T>
where
T: Mul<Output = T> + Copy,
{
    type Output = Vector<T>;

    fn mul(self, scalar: T) -> Vector<T> {
        Vector {
            x: self.x * scalar,
            y: self.y * scalar,
        }
    }
}

impl<T> MulAssign<T> for Vector<T>
where
T: MulAssign + Copy,
{
    fn mul_assign(&mut self, other: T) {
        self.x *= other;
        self.y *= other;
    }
}

impl<T> Div<T> for Vector<T>
where
T: Div<Output = T> + Copy,
{
    type Output = Vector<T>;

    fn div(self, other: T) -> Vector<T> {
        Vector {
            x: self.x / other,
            y: self.y / other,
        }
    }
}

impl<T> DivAssign<T> for Vector<T>
where
T: DivAssign + Copy,
{
    fn div_assign(&mut self, other: T) {
        self.x /= other;
        self.y /= other;
    }
}

impl<T: PartialEq> PartialEq for Vector<T> {
    fn eq(&self, other: &Self) -> bool {
        self.x == other.x && self.y == other.y
    }
}

#[allow(dead_code)]
trait Length {
    type Output;

    fn length(&self) -> Self::Output;
}

impl Length for Vector<f32> {
	type Output = f32;

	fn length(&self) -> Self::Output  {
		(self.x * self.x + self.y * self.y).sqrt()
	}
}

impl Length for Vector<f64> {
	type Output = f64;

	fn length(&self) -> Self::Output  {
		(self.x * self.x + self.y * self.y).sqrt()
	}
}
#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_new() {
        // Test creating a new vector with integers
        let v = Vector::new(10, 20);
        assert_eq!(v.x, 10);
        assert_eq!(v.y, 20);

        // Test creating a new vector with floating point numbers
        let v_f32 = Vector::new(3.5_f32, 4.5_f32);
        assert_eq!(v_f32.x, 3.5_f32);
        assert_eq!(v_f32.y, 4.5_f32);

        // Test creating a new vector with strings
        let v_str = Vector::new("Hello", "World");
        assert_eq!(v_str.x, "Hello");
        assert_eq!(v_str.y, "World");
    }

    #[test]
    fn test_length_f32_1() {
        // Test calculating the length of a vector with f32 components
        let v = Vector::new(3.0_f32, 4.0_f32);
        let length = v.length();
        assert_eq!(length, 5.0);
    }

    #[test]
    fn test_length_f64_1() {
        // Test calculating the length of a vector with f64 components
        let v = Vector::new(3.0_f64, 4.0_f64);
        let length = v.length();
        assert_eq!(length, 5.0);
    }

    #[test]
    fn test_length_f32_zero() {
        // Test length when the vector is zero
        let v = Vector::new(0.0_f32, 0.0_f32);
        let length = v.length();
        assert_eq!(length, 0.0);
    }

    #[test]
    fn test_length_f64_zero() {
        // Test length when the vector is zero
        let v = Vector::new(0.0_f64, 0.0_f64);
        let length = v.length();
        assert_eq!(length, 0.0);
    }

    #[test]
    fn test_add() {
        let v1 = Vector::new(1, 2);
        let v2 = Vector::new(3, 4);
        let result = v1 + v2;
        assert_eq!(result, Vector::new(4, 6));
    }

    #[test]
    fn test_add_assign() {
        let mut v1 = Vector::new(1, 2);
        let v2 = Vector::new(3, 4);
        v1 += v2;
        assert_eq!(v1, Vector::new(4, 6));
    }

    #[test]
    fn test_sub() {
        let v1 = Vector::new(5, 7);
        let v2 = Vector::new(2, 4);
        let result = v1 - v2;
        assert_eq!(result, Vector::new(3, 3));
    }

    #[test]
    fn test_sub_assign() {
        let mut v1 = Vector::new(5, 7);
        let v2 = Vector::new(2, 4);
        v1 -= v2;
        assert_eq!(v1, Vector::new(3, 3));
    }

    #[test]
    fn test_mul_scalar() {
        let v = Vector::new(2, 3);
        let result = v * 3;
        assert_eq!(result, Vector::new(6, 9));
    }

    #[test]
    fn test_mul_assign_scalar() {
        let mut v = Vector::new(2, 3);
        v *= 3;
        assert_eq!(v, Vector::new(6, 9));
    }

    #[test]
    fn test_div_scalar() {
        let v = Vector::new(6, 9);
        let result = v / 3;
        assert_eq!(result, Vector::new(2, 3));
    }

    #[test]
    fn test_div_assign_scalar() {
        let mut v = Vector::new(6, 9);
        v /= 3;
        assert_eq!(v, Vector::new(2, 3));
    }

    #[test]
    fn test_length_f32() {
        let v = Vector::new(3.0_f32, 4.0_f32);
        let length = v.length();
        assert_eq!(length, 5.0);
    }

    #[test]
    fn test_length_f64() {
        let v = Vector::new(3.0_f64, 4.0_f64);
        let length = v.length();
        assert_eq!(length, 5.0);
    }

	#[test]
	fn test_a() {
		let v = Vector {
			x: String::from("Hello, World!"),
			y: String::from("Hello, Rust!"),
		};

		let w = v.clone();

		assert_eq!(&v, &w);
	}

	#[test]
	fn test_b() {
		let v = Vector::new("Hello, World!", "Hello, Rust!");
		let a = v;
		let b = v;
		assert_eq!(a, b);
	}
}