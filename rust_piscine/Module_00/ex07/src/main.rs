extern crate ex07;
use ftkit::ARGS;

fn main() {
    let args = ARGS;
    let query = args[1].as_bytes();
    let pattern = args[2].as_bytes();


	if ex07::lib::strpcmp(query, pattern) {
        println!("yes");
    } else {
        println!("no");
    }
}

#[cfg(test)]
mod tests {
    use ex07::lib::strpcmp;

    #[test]
    fn test_strpcmp() {
        assert!(strpcmp(b"abc", b"abc"));
        assert!(strpcmp(b"abcd", b"ab*"));
        assert!(!strpcmp(b"cab", b"ab*"));
        assert!(strpcmp(b"dcab", b"*ab"));
        assert!(!strpcmp(b"abc", b"*ab"));
        assert!(strpcmp(b"ab000cd", b"ab*cd"));
        assert!(strpcmp(b"abcd", b"ab*cd"));
        assert!(strpcmp(b"", b"****"));
    }
}
