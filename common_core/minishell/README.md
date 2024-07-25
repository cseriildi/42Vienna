# About the minishell project
You can find my minishell git repo [here](https://github.com/cseriildi/minishell).

## Summary
The goal of this project is to recreate a simple version of bash.

- **Allowed external functions**: `readline`, `rl_clear_history`, `rl_on_new_line`, `rl_replace_line`, `rl_redisplay`, `add_history`, `printf`, `malloc`, `free`, `write`, `access`, `open`, `read`, `close`, `fork`, `wait`, `waitpid`, `wait3`, `wait4`, `signal`, `sigaction`, `sigemptyset`, `sigaddset`, `kill`, `exit`, `getcwd`, `chdir`, `stat`, `lstat`, `fstat`, `unlink`, `execve`, `dup`, `dup2`, `pipe`, `opendir`, `readdir`, `closedir`, `strerror`, `perror`, `isatty`, `ttyname`, `ttyslot`, `ioctl`, `getenv`, `tcsetattr`, `tcgetattr`, `tgetent`, `tgetflag`, `tgetnum`, `tgetstr`, `tgoto`, `tputs`

## Useful stuff

## Mandatory Part

After running `make` your program should be executed as `./minishell` and it should behave like bash.
The program should:
- display a promt
- save the command lines to history and be accessible with the up and down arrows
- execute commands with relative and absolute path
- use only one global variable storing the received signal
- not interpret unclosed quotes or any special character not specified below
	- `'` and `"`
	- `<`, `<<`, `>` and  `>>` redirections
	- `|`
	- `$?` should expand to the latest exit status
	- `$` should expand to environment variables
- handle signals like bash
	- `ctrl-C` should display a new prompt on a new line
	- `ctrl-D` should exit the shell
	- `ctrl-\` should do nothing
- implement the builtins below
	- `echo` with option `-n`
	- `cd` with only a relative or absolute path
	- `pwd` with no options
	- `export` with no options
	- `unset` with no options
	- `env` with no options or arguments
	- `exit` with no options

## Bonus Part

For the bonus you should also handle:
- `&&`
- `||`
- `(` and `)` parenthesis for priorities
- `*` wildcards for the current directory 