# About the CPP Module 01 project

## Summary
The goal of the CPP Module projects is to get familiar with C++ programming language quickly.
- **Allowed functions**: Any function from the standard library, if there is a C++ version of the function, use that. The code must compile with c++98.
- **Forbidden functions**: Any function from external libraries and `*printf()`, `*alloc()` and `free()`.

## Useful Stuff


## Exercise 00
The goal of this task is to decide when is it better to allocate on the stack and on thhe heap.
- Create a class called `Zombie` with:
	- one private `name` attribute
	- a member function `void announce(void);`, which prints `<name>: BraiiiiiiinnnzzzZ...` where `<name>` is the instance's name
	- The destructor prints a message with the zombie's name
- Implement two additional functions:
	- `Zombie* newZombie(std::string name);` which creates an instance, sets the name and returns a pointer to the instance to be used outside of the function scope
	- `void randomChump(std::string name);` which also creates an instance, sets the name, but insted of returning a pointer to it announces itself
- Compare the two functions in the main

## Exercise 01

## Exercise 02

## Exercise 03

## Exercise 04

## Exercise 05

## Exercise 06
