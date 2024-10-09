#[allow(dead_code)]
struct Point {
    x: f32,
    y: f32,
}

#[allow(dead_code)]
impl Point {
    fn new(x: f32, y: f32) -> Self {
		Point {
			x,
			y,
		}
	}

    fn zero() -> Self {
		Point {
			x: 0.0,
			y: 0.0,
		}
	}

    fn distance(&self, other: &Self) -> f32 {
		let dx: f32 = self.x - other.x;
		let dy: f32 = self.y - other.y;
		(dx * dx  + dy * dy).sqrt()
	}

    fn translate(&mut self, dx: f32, dy: f32) {
		self.x += dx;
		self.y += dy;

	}
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_new_point() {
        let p = Point::new(3.0, 4.0);
        assert_eq!(p.x, 3.0);
        assert_eq!(p.y, 4.0);
    }

    #[test]
    fn test_zero_point() {
        let p = Point::zero();
        assert_eq!(p.x, 0.0);
        assert_eq!(p.y, 0.0);
    }

    #[test]
    fn test_distance_same_point() {
        let p1 = Point::new(3.0, 4.0);
        let p2 = Point::new(3.0, 4.0);
        assert_eq!(p1.distance(&p2), 0.0);
    }

    #[test]
    fn test_distance_different_points() {
        let p1 = Point::new(0.0, 0.0);
        let p2 = Point::new(3.0, 4.0);
        assert_eq!(p1.distance(&p2), 5.0);
    }

    #[test]
    fn test_translate_point() {
        let mut p = Point::new(1.0, 1.0);
        p.translate(2.0, 3.0);
        assert_eq!(p.x, 3.0);
        assert_eq!(p.y, 4.0);
    }

    #[test]
    fn test_translate_point_negative() {
        let mut p = Point::new(1.0, 1.0);
        p.translate(-1.0, -1.0);
        assert_eq!(p.x, 0.0);
        assert_eq!(p.y, 0.0);
    }
}
