use std::cell::Cell;

#[derive(Copy, Clone, Debug, PartialEq)]

#[allow(dead_code)]
enum Error {
    Success,
    FileNotFound,
    IsDirectory,
    WriteFail,
    ReadFail,
}

thread_local! {
    static LAST_ERROR: Cell<Error> = const {Cell::new(Error::Success)};
}

#[allow(dead_code)]
impl Error {
    fn last() -> Self {
		LAST_ERROR.with(|error| error.get())
	}
    fn make_last(self) {
		LAST_ERROR.with(|error| error.set(self))
	}
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_initial_last_error() {
        assert_eq!(Error::last(), Error::Success);
    }

    #[test]
    fn test_set_last_error() {
        Error::FileNotFound.make_last();
        assert_eq!(Error::last(), Error::FileNotFound);

        Error::WriteFail.make_last();
        assert_eq!(Error::last(), Error::WriteFail);
    }

    #[test]
    fn test_thread_local_behavior() {
        Error::IsDirectory.make_last();
        assert_eq!(Error::last(), Error::IsDirectory);

        std::thread::spawn(|| {
            assert_eq!(Error::last(), Error::Success);
            Error::ReadFail.make_last();
            assert_eq!(Error::last(), Error::ReadFail);
        }).join().unwrap();

        assert_eq!(Error::last(), Error::IsDirectory);
    }
}