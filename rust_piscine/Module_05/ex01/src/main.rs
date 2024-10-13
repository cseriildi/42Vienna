use std::{io::{self, stdout}, sync::{Mutex, Arc}, thread};

struct Logger<W> {
    buffer: Box<[u8]>,
	threshold: usize,
	position: usize,
    writer: W,
}

impl<W> Logger<W> {
    pub fn new(threshold: usize, writer: W) -> Self {
		Logger {
			buffer: vec![0; threshold].into_boxed_slice(),
			threshold,
			position: 0,
			writer
		}
	}
}

impl<W: io::Write> Logger<W> {
    pub fn log(&mut self, message: &str) -> io::Result<()> {
		let len = message.len();
		let text = message.as_bytes();

		if self.threshold > 0 && self.threshold - self.position > len {
			for ch in text {
				self.buffer[self.position] = *ch;
				self.position +=1;
			}
			self.buffer[self.position] = b'\n';
			self.position +=1;

			if self.position == self.threshold {
				self.flush()?;
			}
		}
		else {
			self.flush()?;
			self.writer.write_all(text)?;
			self.writer.write_all(b"\n")?;
		}
		Ok(())
	}

    pub fn flush(&mut self) -> io::Result<()> {
		self.writer.write_all(&self.buffer[0..self.position])?;
		self.position = 0;
		Ok(())
	}
}
fn main () -> thread::Result<()> {

	const THREAD_COUNT: usize = 10;
	const THRESHOLD: usize = 42;
	let writer = stdout();
	
	let mut threads = Vec::new();
	
	let logger = Arc::new(Mutex::new(Logger::new(THRESHOLD, writer)));
	for id in 0..THREAD_COUNT {
		let logger = Arc::clone(&logger);
		threads.push(thread::spawn(move || {
			for number in 0..THREAD_COUNT {
				let text = ["hello ".to_string(), number.to_string(), " from thread ".to_string(), id.to_string(), "!".to_string()];
				let _ = logger.lock().unwrap().log(&text.concat());
			}
		}));
	}
	for thr in threads {
		thr.join()?;
	}
    let mut logger = logger.lock().unwrap();
    let _ = logger.flush();
	Ok(())
}