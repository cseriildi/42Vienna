# About the push_swap project

In this project you have to sort data on a stack with a limited set of instructions using the lowest possible number of actions.

**Allowed external functions:**  `read`, `write`, `malloc`, `free`, `exit`

## Useful stuff
- Bash command to generate random numbers and save them in a variable: ```ARG=$(shuf -i 0-2147483647 -n 500)```
- Another [random number generator](https://numbergenerator.org/#!numbers=500&low=-2147483648&high=2147483647&unique=true&csv=&oddeven=&oddqty=0&sorted=false&addfilters=)
- [Clickable push_swap game](https://github.com/stevebalk/push-swap-clicker)  to get familiar with the task
- [Push_swap visualizer](https://github.com/o-reo/push_swap_visualizer)  to visualize your program
- [The explanation of the algorithm I chose](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [A video explanation for the algorithm](https://www.youtube.com/watch?v=OaG81sDEpVk&t=4217s)

## Mandatory Part

We have 2 stacks. `Stack A` containing the numbers (unique numbers between the `INT_MIN` and `INT_MAX`) and an empty `Stack B`.

The numbers have to be sorted using the two stacks and these instructions:
- `sa` (swap a): Swap the first 2 elements of `Stack A`
- `sb` (swap b): Swap the first 2 elements of `Stack B`.
- `ss`: Execute `sa` and `sb` simultaneously.
- `pa` (push a): Take the first element of `Stack B` and put it at the top of `Stack A`.
- `pb` (push b): Take the first element of `Stack A` and put it at the top of `Stack B`.
- `ra` (rotate a): Shift up all elements of `Stack A` by 1. The first element becomes the last one.
- `rb` (rotate b): Shift up all elements of `Stack B` by 1. The first element becomes the last one.
- `rr`: Execute `ra` and `rb` simultaneously.
- `rra` (reverse rotate a): Shift down all elements of `Stack A` by 1. The last element becomes the first one.
- `rrb` (reverse rotate b): Shift down all elements of `Stack B` by 1. The last element becomes the first one.
- `rrr`: Execute `rra` and `rrb` simultaneously.

Write a program named push_swap that displays the smallest list of instructions to sort `Stack A`.

After running `make` the program can be executed like this:

`./push_swap 2 1 3 6 5 8` *(the list of numbers as separate arguments)* or `./push_swap "2 1 3 6 5 8"` *(the list of numbers as one string)*.

The output should be:
- `Error` if any of the numbers are out of the integer range, not unique or not a number.
- The list of instructions *(needed to sort the numbers)* separated by newlines. 

The program should sort 500 random numbers under 5500 steps.

*To check the number of instructions: `./push_swap 2 1 3 6 5 8 | wc -l`*

## Bonus Part

We have to create a program that reads the instructions from the Standard Input, and checks if the numbers can be sorted by the instructions.

After running `make bonus` the program can be executed like this:

`./checker 2 1 3 6 5 8` or `./checker "2 1 3 6 5 8"`. 

It could be executed together with the mandatory part like this:

`ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG`

The output should be:
- `Error` if any of the numbers are out of the integer range, not unique or not a number or if any of the instructions read from the Standard Input are not an existing instruction.
- `OK` in case the instructions sort the numbers.
- `KO` otherwise.
