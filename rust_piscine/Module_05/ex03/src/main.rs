use std::sync::mpsc::sync_channel;
use std::thread::{spawn, sleep};
use std::time::Duration;
use ftkit::ARGS;
use std::io::{self, BufRead};

fn main() {
    if ARGS.len() != 2 {
        return ;
    }

    let brain_size = match ARGS[1].parse::<usize>() {
		Ok(size) => size,
		Err(_) => return,
	};

    let (tx, rx) = sync_channel(brain_size);

    spawn(move || {
		while let Ok(word) = rx.recv() {
			println!("the philosopher is thinking about {}", word);
			 sleep(Duration::from_secs(5));
		}
	});

    for line in io::stdin().lock().lines() {
        if let Ok(word) = line {
			if tx.try_send(word).is_err() {
				println!("the philosopher's head is full");
			}
		}
		else {
			break;
        }
    }
    drop(tx);
}
