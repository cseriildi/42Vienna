fn is_leap_year(year: u32) -> bool {
	if year == 0 {
		panic!("Year passed is {}", year);
	}
	match (year % 400, year % 100 , year % 4) {
		(0, _, _) => true,
		(_, 0, _) => false,
		(_, _, 0) => true,
		_ => false
	}
}

fn num_days_in_month(year: u32, month: u32) -> u32 {
	let months:[u32;12] = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
	if is_leap_year(year) && month == 2 {
		29
	}
	else if (1..13).contains(&month) {
		months[(month - 1) as usize]
	}
	else {
		panic!("Month is out of range 1..13")
	}
}

fn main() {

	let mut days_from_beginning: u32 = 13;
	let months: [&str; 12] = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"];

	'here: for year in 1..2025 {
		for month in 1..13 {
			if year == 2024 && month == 10 {
				break 'here
			}
			if days_from_beginning % 7 == 5 {
				std::println!("Friday, {} 13, {year}", months[(month - 1) as usize]);
			}
			days_from_beginning += num_days_in_month(year, month);
		}
	}
}

#[cfg(test)]
mod tests {
	#[test]
	fn leap_year_test_1600() {
		let result = crate::is_leap_year(1600);
		assert_eq!(result, true);
	}
	#[test]
	fn leap_year_test_1500() {
		let result = crate::is_leap_year(1500);
		assert_eq!(result, false);
	}
	#[test]
	fn leap_year_test_2004() {
		let result = crate::is_leap_year(2004);
		assert_eq!(result, true);
	}
	#[test]
	fn leap_year_test_2003() {
		let result = crate::is_leap_year(2003);
		assert_eq!(result, false);
	}
	#[test]
	#[should_panic]
	fn leap_year_test_0() {
		crate::is_leap_year(0);
	}

	#[test]
	fn num_days_in_month_1600_feb() {
		let result = crate::num_days_in_month(1600, 2);
		assert_eq!(result, 29);
	}
	#[test]
	fn num_days_in_month_1500_feb() {
		let result = crate::num_days_in_month(1500, 2);
		assert_eq!(result, 28);
	}
	#[test]
	fn num_days_in_month_2004_jan() {
		let result = crate::num_days_in_month(2004, 1);
		assert_eq!(result, 31);
	}
	#[test]
	fn num_days_in_month_2003_jun() {
		let result = crate::num_days_in_month(2003, 6);
		assert_eq!(result, 30);
	}
	#[test]
	#[should_panic]
	fn num_days_in_month_panic() {
		crate::num_days_in_month(2000, 0);
	}
}
