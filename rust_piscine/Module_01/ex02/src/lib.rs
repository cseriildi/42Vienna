#[allow(dead_code)]
const fn color_name(color: &[u8; 3]) -> &'static str {
	match (color[0], color[1], color[2]) {
		(0, 0, 0) => "pure black",
		(255, 255, 255) => "pure white",
		(255, 0, 0) => "pure red",
		(0, 255, 0) => "pure green",
		(0, 0, 255) => "pure blue",
		(128, 128, 128) => "perfect grey",
		(0..31, 0..31, 0..31) => "almost black",
		(129..=255, 0..=127, 0..=127) => "redish",
		(0..=127, 129..=255, 0..=127) => "greenish",
		(0..=127, 0..=127, 129..=255) => "blueish",
		_ => "unknown"
	}
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_pure_black() {
        let color = [0, 0, 0];
        let name = color_name(&color);
        assert_eq!(name, "pure black");
    }

    #[test]
    fn test_pure_white() {
        let color = [255, 255, 255];
        let name = color_name(&color);
        assert_eq!(name, "pure white");
    }

    #[test]
    fn test_pure_red() {
        let color = [255, 0, 0];
        let name = color_name(&color);
        assert_eq!(name, "pure red");
    }

    #[test]
    fn test_pure_green() {
        let color = [0, 255, 0];
        let name = color_name(&color);
        assert_eq!(name, "pure green");
    }

    #[test]
    fn test_pure_blue() {
        let color = [0, 0, 255];
        let name = color_name(&color);
        assert_eq!(name, "pure blue");
    }

    #[test]
    fn test_perfect_gray() {
        let color = [128, 128, 128];
        let name = color_name(&color);
        assert_eq!(name, "perfect grey");
    }

    #[test]
    fn test_almost_black() {
        let color = [30, 30, 30];
        let name = color_name(&color);
        assert_eq!(name, "almost black");
    }

    #[test]
    fn test_border_almost_black() {
        let color = [0, 30, 30];
        let name = color_name(&color);
        assert_eq!(name, "almost black");
    }

    #[test]
    fn test_border_redish_lower() {
        let color = [129, 0, 0];
        let name = color_name(&color);
        assert_eq!(name, "redish");
    }

    #[test]
    fn test_border_redish_upper() {
        let color = [255, 127, 127];
        let name = color_name(&color);
        assert_eq!(name, "redish");
    }

    #[test]
    fn test_border_greenish_lower() {
        let color = [0, 129, 0];
        let name = color_name(&color);
        assert_eq!(name, "greenish");
    }

    #[test]
    fn test_border_greenish_upper() {
        let color = [127, 255, 127];
        let name = color_name(&color);
        assert_eq!(name, "greenish");
    }

    #[test]
    fn test_border_blueish_lower() {
        let color = [0, 0, 129];
        let name = color_name(&color);
        assert_eq!(name, "blueish");
    }

    #[test]
    fn test_border_blueish_upper() {
        let color = [127, 127, 255];
        let name = color_name(&color);
        assert_eq!(name, "blueish");
    }

    #[test]
    fn test_unknown_color() {
        let color = [100, 100, 100];
        let name = color_name(&color);
        assert_eq!(name, "unknown");
    }

    #[test]
    fn test_boundary_color_redish() {
        let color = [129, 127, 127];
        let name = color_name(&color);
        assert_eq!(name, "redish");
    }

    #[test]
    fn test_boundary_color_greenish() {
        let color = [127, 129, 127];
        let name = color_name(&color);
        assert_eq!(name, "greenish");
    }

    #[test]
    fn test_boundary_color_blueish() {
        let color = [127, 127, 129];
        let name = color_name(&color);
        assert_eq!(name, "blueish");
    }

    #[test]
    fn test_redish_below_range() {
        let color = [128, 127, 127];
        let name = color_name(&color);
        assert_eq!(name, "unknown");
    }

    #[test]
    fn test_greenish_below_range() {
        let color = [127, 128, 127];
        let name = color_name(&color);
        assert_eq!(name, "unknown");
    }

    #[test]
    fn test_blueish_below_range() {
        let color = [127, 127, 128];
        let name = color_name(&color);
        assert_eq!(name, "unknown");
    }
}
