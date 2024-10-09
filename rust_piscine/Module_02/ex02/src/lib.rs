#[derive(PartialEq, Debug)]
#[allow(dead_code)]
enum PizzaStatus {
	Ordered,
	Cooking,
	Cooked,
	Delivering,
	Delivered,
}

#[allow(dead_code)]
impl PizzaStatus {
	fn from_delivery_time(ordered_days_ago: u32) -> Self {
		match ordered_days_ago {
			0..2 => PizzaStatus::Ordered,
			2..7 => PizzaStatus::Cooking,
			7..10 => PizzaStatus::Cooked,
			10..17 => PizzaStatus::Delivering,
			_ => PizzaStatus::Delivered
		}
	}

	fn get_delivery_time_in_days(&self) -> u32 {
		match self {
			PizzaStatus::Ordered => 17,
			PizzaStatus::Cooking => 15,
			PizzaStatus::Cooked => 10,
			PizzaStatus::Delivering => 7,
			PizzaStatus::Delivered => 0
		}
	}
}


#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_from_delivery_time_ordered() {
        assert_eq!(PizzaStatus::from_delivery_time(1), PizzaStatus::Ordered);
    }

    #[test]
    fn test_from_delivery_time_cooking() {
        assert_eq!(PizzaStatus::from_delivery_time(3), PizzaStatus::Cooking);
    }

    #[test]
    fn test_from_delivery_time_cooked() {
        assert_eq!(PizzaStatus::from_delivery_time(8), PizzaStatus::Cooked);
    }

    #[test]
    fn test_from_delivery_time_delivering() {
        assert_eq!(PizzaStatus::from_delivery_time(12), PizzaStatus::Delivering);
    }

    #[test]
    fn test_from_delivery_time_delivered() {
        assert_eq!(PizzaStatus::from_delivery_time(18), PizzaStatus::Delivered);
    }

    #[test]
    fn test_from_delivery_time_edge_case_cooking() {
        assert_eq!(PizzaStatus::from_delivery_time(2), PizzaStatus::Cooking);
    }

    #[test]
    fn test_from_delivery_time_edge_case_cooked() {
        assert_eq!(PizzaStatus::from_delivery_time(7), PizzaStatus::Cooked);
    }

    #[test]
    fn test_from_delivery_time_edge_case_delivering() {
        assert_eq!(PizzaStatus::from_delivery_time(10), PizzaStatus::Delivering); 
    }

    #[test]
    fn test_from_delivery_time_edge_case_delivered() {
        assert_eq!(PizzaStatus::from_delivery_time(17), PizzaStatus::Delivered);
    }

    #[test]
    fn test_get_delivery_time_in_days_ordered() {
        assert_eq!(PizzaStatus::Ordered.get_delivery_time_in_days(), 17);
    }

    #[test]
    fn test_get_delivery_time_in_days_cooking() {
        assert_eq!(PizzaStatus::Cooking.get_delivery_time_in_days(), 15);
    }

    #[test]
    fn test_get_delivery_time_in_days_cooked() {
        assert_eq!(PizzaStatus::Cooked.get_delivery_time_in_days(), 10);
    }

    #[test]
    fn test_get_delivery_time_in_days_delivering() {
        assert_eq!(PizzaStatus::Delivering.get_delivery_time_in_days(), 7);
    }

    #[test]
    fn test_get_delivery_time_in_days_delivered() {
        assert_eq!(PizzaStatus::Delivered.get_delivery_time_in_days(), 0);
    }

    #[test]
    fn test_get_delivery_time_in_days_edge_case_ordered() {
        assert_eq!(PizzaStatus::Ordered.get_delivery_time_in_days(), 17); // Edge case
    }

    #[test]
    fn test_get_delivery_time_in_days_edge_case_cooking() {
        assert_eq!(PizzaStatus::Cooking.get_delivery_time_in_days(), 15); // Edge case
    }

    #[test]
    fn test_get_delivery_time_in_days_edge_case_cooked() {
        assert_eq!(PizzaStatus::Cooked.get_delivery_time_in_days(), 10); // Edge case
    }

    #[test]
    fn test_get_delivery_time_in_days_edge_case_delivering() {
        assert_eq!(PizzaStatus::Delivering.get_delivery_time_in_days(), 7); // Edge case
    }

    #[test]
    fn test_get_delivery_time_in_days_edge_case_delivered() {
        assert_eq!(PizzaStatus::Delivered.get_delivery_time_in_days(), 0); // Edge case
    }
}
