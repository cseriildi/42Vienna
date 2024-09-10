# About the CPP Module 01 project

## Summary
The goal of the CPP Module projects is to get familiar with C++ programming language quickly.
- **Allowed functions**: Any function from the standard library, if there is a C++ version of the function, use that. The code must compile with c++98.
- **Forbidden functions**: Any function from external libraries and `*printf()`, `*alloc()` and `free()`.

## Useful Stuff
- [Documentation and Tutorial for C++](https://cplusplus.com/doc/tutorial/)

## Exercise 00
The goal of this task is to decide when is it better to allocate on the stack and on the heap.
- Create a class called `Zombie` with:
	- one private `name` attribute
	- a member function `void announce(void);`, which prints `<name>: BraiiiiiiinnnzzzZ...` where `<name>` is the instance's name
	- The destructor prints a message with the zombie's name
- Implement two additional functions:
	- `Zombie* newZombie(std::string name);` which creates an instance, sets the name and returns a pointer to the instance to be used outside of the function scope
	- `void randomChump(std::string name);` which also creates an instance, sets the name, but insted of returning a pointer to it announces itself
- Compare the two functions in the main

## Exercise 01
In this task you'll have to create multiple instances at the same time
- Use the previous Zombie class
- Create `Zombie* zombieHorde(int N, std::string name);` function which should create `N` instances with the given name on the heap
- In the name call the `zombieHorde()` function and then the `announce()` funciton on all instances.

## Exercise 02
In this task you'll play around with pointers and refrences to learn about address manipulation.
- Initialize
	- a string `"HI THIS IS BRAIN"`
	- a pointer to it called `stringPTR`
	- a refrence to it called `stringREF`
- Print the memory address
	- of the string
	- held by `stringPTR`
	- held by `stringREF`
- Print the value
	- of the string
	- pointed to by `stringPTR`
	- pointed to by `stringREF`

## Exercise 03
To further deepen your knowledge on address manipulation in this task you'll have to decide when is it better to use a pointer and when a reference to a value.
- Create a class called `Weapon`
	- with a `type` private attribute
	- a `setType` and a `getType` member functions
- Create 2 classes called `HumanA` and `HumanB`
	- with 2 private attributes: `name` and `weapon`
	- define an `attack` function that should display `<name> attacks with their <weapon type>`
	- the constructor of `HumanA` should take the `name` and `weapon` attributes, the constructor of the `HumanB` should only take the `name`, since `HumanA` will always have a weapon but `HumanB` might not have one

## Exercise 04
In this task you'll learn about file management and manipulation
- Write a program that takes 3 parameters: 
	- filename
	- string to replace
	- string to replace with
- Open the file
- Replace the word
- It is forbidden to use the std::string::replace since that what you'll have to recreate
- Write your own test cases

## Exercise 05

## Exercise 06
