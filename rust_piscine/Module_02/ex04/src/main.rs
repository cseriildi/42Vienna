use std::io::{self, Write};

enum Command {
	Todo(String),   // Command: "TODO"
    Done(usize),    // Command: "DONE"
    Purge,          // Command: "PURGE"
    Quit,           // Command: "QUIT"
}

impl Command {
	fn prompt() -> Self {
		loop {
			print!("> ");
			let _ = io::stdout().flush();
            let line = ftkit::read_line();
				
            if let Some(stripped) = line.strip_prefix("TODO ") {
				if !stripped.trim().is_empty() {
					return Command::Todo(stripped.trim().to_string());
				}
            }
			else if let Some(stripped) = line.strip_prefix("DONE ") {
                if let Ok(index) = stripped.trim().parse() {
                    return Command::Done(index);
                }
            }
			else if let Some(stripped) = line.strip_prefix("PURGE") {
				if stripped.trim().is_empty() {
                	return Command::Purge;
				}
            }
			else if let Some(stripped) = line.strip_prefix("QUIT") {
				if stripped.trim().is_empty() {
                	return Command::Quit;
				}
            }
        }
    }
}

struct TodoList {
    todos: Vec<String>,
    dones: Vec<String>,
}

impl TodoList {
    fn new() -> Self {
		TodoList {
			todos: Vec::new(),
			dones: Vec::new()
		}
	}

    fn display(&self) {
		println!();
		if !self.todos.is_empty() {
			for (i, todo) in self.todos.iter().enumerate() {
				println!("	{i} [ ] {todo}");
			}
		}
		if !self.dones.is_empty() {
			for done in &self.dones {
				println!("	[x] {done}");
			}
		}
		println!();
	}

    fn add(&mut self, todo: String) {
		self.todos.push(todo);
	}

    fn done(&mut self, index: usize) {
		if index < self.todos.len() {
			self.dones.push(self.todos[index].to_string());
			self.todos.remove(index);
		}
	}

    fn purge(&mut self) {
		self.dones.clear();
	}
}

fn main() {
    let mut todo_list = TodoList::new();

    loop {
        todo_list.display();

        match Command::prompt() {
            Command::Todo(todo_item) => todo_list.add(todo_item),
            Command::Done(index) => todo_list.done(index),
            Command::Purge => todo_list.purge(),
            Command::Quit => break
        }
    }
}
