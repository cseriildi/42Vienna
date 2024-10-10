#[derive(Debug, PartialEq)]
pub enum Token<'a> {
    Word(&'a str),
    RedirectStdout,
    RedirectStdin,
    Pipe,
}

pub fn next_token<'a>(s: &mut &'a str) -> Option<Token<'a>> {
	*s = s.trim_start(); 

	if s.is_empty() {
		return None;
	}
	for (i, c) in s.char_indices() {
		if i == 1 {
			break;
		}
		match c {
			'>' => {
				*s = &s[1..];
				return Some(Token::RedirectStdout);
			}
			'<' => {
				*s = &s[1..];
				return Some(Token::RedirectStdin);
			}
			'|' => {
				*s = &s[1..];
				return Some(Token::Pipe);
			}
			_ => {}
		}
	}

	let mut end = 0;
	for (i, c) in s.char_indices() {
		if c == '>' || c == '<' || c == '|' || c.is_whitespace() {
			let word = &s[0..i];
			*s = &s[i..];
			return Some(Token::Word(word));
		}
		end = i;
	}

	let word = &s[0..end];
	*s = "";
	return Some(Token::Word(word));
}

