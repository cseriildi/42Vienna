use ex06::next_token;

fn main() {
    let mut args = std::env::args();

    args.next();
    match args.next() {
        Some(arg) => {
            if args.next().is_some() {
                eprintln!("error: exactly one argument expected");
                return;
            }
            let mut arg_str: &str = &arg;
            while let Some(token) = next_token(&mut arg_str) {
                println!("{:?}", token); // Debug output of tokens
            }
        }
        None => eprintln!("error: exactly one argument expected"),
    }
}