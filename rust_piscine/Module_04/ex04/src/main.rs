use std::io::{self, Read};
use std::process::{Command, Stdio, Child};

fn main() -> Result<(),io::Error> {
	let mut args: Vec<String> = std::env::args().collect();
	args.remove(0);
	let mut commands = Vec::new();
	let mut current_command: Vec<String> = Vec::new();
	let mut children: Vec<Child> = Vec::new();

	for curr in &args {
		if curr != "," {
			current_command.push(curr.clone());
		}
		else {
			if !current_command.is_empty() {
				let command_name = current_command.remove(0);
				let mut c = Command::new(command_name);
				c.args(current_command.clone());
                commands.push(c);
			}
			current_command.clear();
		}
	}
	if !current_command.is_empty() {
		let command_name = current_command.remove(0);
		let mut c = Command::new(command_name);
		c.args(current_command.clone());
        commands.push(c);
	}
	for mut comm in commands {
		let child: Child = comm.stdout(Stdio::piped()).stderr(Stdio::null()).spawn()?;
		children.push(child);
	}
    while !children.is_empty() {
        let mut remaining_children = Vec::new();
        
        for mut child in children {
            if let Some(_status) = child.try_wait()? {
				if let Some(mut output) = child.stdout.take() {
					let mut buf = String::new();
					let _= output.read_to_string(&mut buf);
					println!("=======\n{buf}");
				}
            } else {
				remaining_children.push(child);
            }
        }
        children = remaining_children;
    }
	Ok(())
}
