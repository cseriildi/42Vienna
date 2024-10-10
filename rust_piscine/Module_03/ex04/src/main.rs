use std::str::FromStr;
use std::fmt;

struct Time {
    hours: u32,
    minutes: u32,
}

#[derive(Debug)]
enum TimeParseError {
    MissingColon,
    InvalidLength,
    InvalidNumber,
}

impl fmt::Display for TimeParseError {
	fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
		match self {
			TimeParseError::MissingColon => write!(f, "missing ':'"),	
			TimeParseError::InvalidLength=> write!(f, "invalid length"),
			TimeParseError::InvalidNumber=> write!(f, "invalid number")
		}
	}
}

impl fmt::Display for Time {
	fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
		let h = match self.hours {
			1 => "hour",
			_ => "hours"
		};
		let m = match self.minutes {
			1 => "minute",
			_ => "minutes"
		};
		write!(f, "{} {h}, {} {m}", self.hours, self.minutes)
	}
}
impl fmt::Debug for Time {
	fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
		let h = match self.hours {
			1 => "hour",
			_ => "hours"
		};
		let m = match self.minutes {
			1 => "minute",
			_ => "minutes"
		};
		if f.alternate() {
			return write!(f, "{h}:{}\n{m}:{}", self.hours, self.minutes);
		}
		write!(f, "{}:{}", self.hours, self.minutes)
	}
}

impl FromStr for Time {

	type Err = TimeParseError;

	fn from_str(s: &str) -> Result<Self, Self::Err> {
		let str: &[u8] = s.as_bytes();
		let mut len = 0;

		for _ch in str {
			len += 1;
		}
		if len != 5 {
			return Err(TimeParseError::InvalidLength);
		}

		match (str[0], str[1], str[2], str[3], str[4]) {
			(48..50, 48..58, 58, 48..54, 48..58) => {},
			(50, 48..52, 58, 48..54, 48..58)  => {},
			(58, _, _, _, _)  => return Err(TimeParseError::InvalidLength),
			(_, 58, _, _, _)  => return Err(TimeParseError::InvalidLength),
			(_, _, _, 58, _)  => return Err(TimeParseError::InvalidLength),
			(_, _, _, _, 58)  => return Err(TimeParseError::InvalidLength),
			(_, _, 58, _, _)  => return Err(TimeParseError::InvalidNumber),
			_ => return Err(TimeParseError::MissingColon)
		}

		let hours: u32 = ((str[0] - b'0') * 10 + str[1] - b'0') as u32;
		let minutes: u32 = ((str[3] - b'0') * 10 + str[4] - b'0') as u32;
		Ok(Time {hours, minutes})
	}
}

fn main() {
    let a: Time = "12:20".parse().unwrap();
    let b: Time = "15:14".parse().unwrap();

    println!("{a}");
    println!("{b}");

    let err1: TimeParseError = "12.20".parse::<Time>().unwrap_err();
    let err2: TimeParseError = "12:2".parse::<Time>().unwrap_err();
    let err3: TimeParseError = "12:2a".parse::<Time>().unwrap_err();
    println!("error: {err1}");
    println!("error: {err2}");
    println!("error: {err3}");
}


#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_valid_time_parsing() {
        let time: Time = "12:34".parse().unwrap();
        assert_eq!(time.hours, 12);
        assert_eq!(time.minutes, 34);
        assert_eq!(format!("{}", time), "12 hours, 34 minutes");

        let time: Time = "05:15".parse().unwrap();
        assert_eq!(time.hours, 5);
        assert_eq!(time.minutes, 15);
        assert_eq!(format!("{}", time), "5 hours, 15 minutes");
    }

    #[test]
    fn test_display_format_singular() {
        let time: Time = "01:01".parse().unwrap();
        assert_eq!(format!("{}", time), "1 hour, 1 minute");
    }

    #[test]
    fn test_display_format_plural() {
        let time: Time = "08:30".parse().unwrap();
        assert_eq!(format!("{}", time), "8 hours, 30 minutes");
    }

    #[test]
    fn test_invalid_length_error() {
        let err: TimeParseError = "12:3".parse::<Time>().unwrap_err();
        assert_eq!(format!("{}", err), "invalid length");

        let err: TimeParseError = "123:45".parse::<Time>().unwrap_err();
        assert_eq!(format!("{}", err), "invalid length");
    }

    #[test]
    fn test_missing_colon_error() {
        let err: TimeParseError = "12345".parse::<Time>().unwrap_err();
        assert_eq!(format!("{}", err), "missing ':'");

        let err: TimeParseError = "12-34".parse::<Time>().unwrap_err();
        assert_eq!(format!("{}", err), "missing ':'");
    }

    #[test]
    fn test_invalid_number_error() {
        let err: TimeParseError = "12:3a".parse::<Time>().unwrap_err();
        assert_eq!(format!("{}", err), "invalid number");

        let err: TimeParseError = "aa:bb".parse::<Time>().unwrap_err();
        assert_eq!(format!("{}", err), "invalid number");
    }

    #[test]
    fn test_out_of_range_hours() {
        let err: TimeParseError = "24:00".parse::<Time>().unwrap_err();
        assert_eq!(format!("{}", err), "invalid number");

        let err: TimeParseError = "25:10".parse::<Time>().unwrap_err();
        assert_eq!(format!("{}", err), "invalid number");
    }

    #[test]
    fn test_out_of_range_minutes() {
        let err: TimeParseError = "12:60".parse::<Time>().unwrap_err();
        assert_eq!(format!("{}", err), "invalid number");

        let err: TimeParseError = "09:99".parse::<Time>().unwrap_err();
        assert_eq!(format!("{}", err), "invalid number");
    }
}