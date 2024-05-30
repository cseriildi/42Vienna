## About the pipex project

### Summary
This project focuses on using **pipes**. You will learn about **processes**, how to create them using **fork**, and how to connect them using **pipes**.

### Useful stuff
- Playlist to get familiar with [Unix Processes in C](https://youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&si=iyDYLxQotEdMbpUW)

### Mandatory
The program should handle two commands and should work like the original command line:

`< file1 cmd1 | cmd2 > file2`

Where the first command reads from the `file1`, executes, and passes the result through the pipe to the second command, which reads it, executes, and writes the result to `file2`.

After running `make` you can execute your program like this:

`./pipex file1 cmd1 cmd2 file2`

[Jump to the walkthrough](#walkthrough-for-the-mandatory-part)

### Bonus
The bonus part should handle multiple commands, similar to the mandatory part. 

After running `make bonus`, this:

`./pipex file1 cmd1 cmd2 cmd3 cmd4 cmd5 file2`

should behave like this:

`< file1 cmd1 | cmd2 | cmd3 | cmd4 | cmd5 > file2`

If the first argument is **here_doc**, then:

`./pipex here_doc LIMITER cmd cmd1 file`

should behave like:

`cmd << LIMITER | cmd1 >> file`

Where the first command reads from the Standard Input until it finds the LIMITER and the result after the last command gets appended to the file.

[Jump to the walkthrough](#walkthrough-for-the-bonus)

### Walkthrough for the mandatory part 

💡 *Click on a* ▶ *for a hint.*

<details><summary> Check the number of arguments and parse them as you'd like</summary>

- Declare your main like this:

	`int	main(int argc, char **argv, char **env);`

- The environment variables will be accessible through `env`, you can check environment variables in the terminal with the `env` command.
- You can find the absolute path to the executable commands in the `PATH` variable. (On Linux, they are usually in the `/bin` or `/usr/bin` folder, but do **NOT** hardcode the folder).
- Use the `access()` function to check if the file exists and is executable.
- Use `ft_split()` to create a list of arguments from the command for `execve()`.
- Use `ft_strjoin()` to join the folder and the first element of the argument list to get the absolute path (don't forget the `/` in between).
</details>
<details><summary>open a pipe </summary>

`int pipe_fd[2]; pipe(pipe_fd);`

*`pipe_fd[0]` is the pipe's reading end and the `pipe_fd[1]` is the writing end*
</details>
<details><summary>create a copy of your current process by forking it </summary>

`pid_t	pid; fork(pid);`

*it will create a child process with `pid == 0` and a parent process with `pid > 0`*
</details>

#### In the child process:
<details><summary>close the reading end of the pipe since you won't use it</summary>

`close(pipe_fd[0]);`
</details>
<details><summary>open the file1 with read permission </summary>

`fd = open(filename, O_RDONLY, 0777);`
</details>
<details><summary>copy the file's content to the Standard Input so the command can read it</summary>

`dup2(fd, STDIN_FILENO);`
</details>
<details><summary>close the file</summary>

`close(fd);`
</details>
<details><summary>copy the pipe's writing end to the Standard Output</summary>

`dup2(pipe_fd[1], STDOUT_FILENO);`
</details>
<details><summary>close the pipe's write end</summary>

`close(pipe_fd[1]);`
</details>
<details><summary>execute the command (in case of successful execution the process ends) </summary>

`execve(full_path_to_the_command, command_arguments_as_a_list, environment);`
</details>

#### In the parent process:
<details><summary>close the pipe's writing end </summary>

`close(pipe_fd[1]);`
</details>
<details><summary>open the file2 with write permission (if it doesn't exist create it)</summary>

`fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);`
</details>
<details><summary>copy the content of the pipe's reading end to the Standard Input</summary>

`dup2(pipe_fd[0], STDIN_FILENO);`
</details>
<details><summary>close the pipe's reading end</summary>

`close(pipe_fd[0]);`
</details>
<details><summary>copy the file's content to the Standard Output</summary>

`dup2(fd, STDOUT_FILENO);`
</details>
<details><summary>close the file</summary>

`close(fd);`
</details>
<details><summary>execute the command (in case of successful execution the process ends) </summary>

`execve(full_path_to_the_command, command_arguments_as_a_list, environment);`
</details>

### Walkthrough for the bonus
- Similar to the mandatory part, check the arguments and parse them
- Pipe and fork

#### In the child process
- Close the pipe's reading end
- If the first argument is **here_doc**:
	- Create a temporary file with a random name and open it with write permission
	- Open the same file with read permission
	- Using the get_next_line function *(from your previous project)* read from the Standard Input and write each line to the temporary file until you read the second argument which is the LIMITER
	- Close the file you wrote in
- If the first argument is a file:
	- Open the file with read permission
- Copy the file's content to the Standard Input
- Close the file
- If you created a temporary file delete it
- Copy the pipe's write end to the Standard Output
- Close the pipe's write end
- Execute the command

#### In the parent process

- Wait for the child process to finish
- If you have more than 2 commands, repeat the following steps until you execute the second-to-last command:
		
	- Pipe (use another integer array) and fork
	- **In the child process:**
		
		-  Close the new pipe's read end and the old pipe's write end
		- Copy the old pipe's read end to the Standard Input
		- Close old pipe's read end
		- Copy the new pipe's write end to the Standard Output
		- Close new pipe's write end
		- Execute the command
	- **In the parent process:**
		
		- Close the old pipe's read and write ends
		- Set the old pipe's read and write ends to the new pipe's read and write ends
- Close the pipe's write end
- If the first argument was **here_doc** and the outfile exists open it in append mode
- Otherwise open/create the outfile
- Copy the pipe's read end to the Standard Input
- Close the pipe's read end
- Copy the file's content to the Standard Output
- Close the file
- Execute the command

Don't forget to always check if a function call fails, throw errors. Free when you have to. It's good practice to use different exit codes.
