# About the get_next_line project

## Summary
In this project you will write a function that returns a line read from a file descriptor.
- **Allowed external functions**: `read`, `malloc`, `free`
- **Prototype**: `char *get_next_line(int fd);`

## Useful Stuff
- [Video explanation for get_next_line](https://youtu.be/8E9siq7apUU?si=1TH07FZkxCtrLNl7)
- [Video about static variables](https://youtu.be/OngGUoENgWo?si=uVp-w_SecWatvGkL)

## Mandatory Part
- Write a function that returns a line read from a file descriptor.
- Calling the `get_next_line()` function multiple times should return the next line read from the file descriptor, including the terminating newline character, except if the end of file was reached and does not end with a newline character.
- The function should read from both a file and standard input.
- Use static variables to maintain state between function calls.
- Adding the option `-D BUFFER_SIZE=n` when compiling should define the buffer size for `read()`.
- It is forbidden to use `lseek()` and global variables.

## Bonus Part
- Use only one static variable.
- Manage multiple file descriptors at the same time without losing track of each file descriptor’s reading position.

