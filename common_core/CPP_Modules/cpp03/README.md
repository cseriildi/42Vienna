# About the CPP Module 03 Project

## Summary
The goal of the CPP Module projects is to get familiar with the C++ programming language quickly.
This project specifically focuses on `virtual inheritance` and `the diamond problem`.

>**Allowed:** Any function from the standard library. If there is a C++ version of a function, use that. The code must compile with C++98.
>
>**Forbidden:** Any function from external libraries, as well as `*printf()`, `*alloc()` and `free()`. Containers (`vector`, `list`, `map`, ...) and algorithms (functions from the `algorithm` header).


## Useful Stuff
- [Multiple inheritance](https://www.learncpp.com/cpp-tutorial/multiple-inheritance/)

## Exercise 00

- Create a class `ClapTrap`
- Private attributes:
	- `name`
	- `hitPoints`
	- `energyPoints`
	- `attackDamage`

- Member functions:
	- `void attack(const std::string& target);`  
		Prints an attack message. Costs 1 energy point.
	- `void takeDamage(unsigned int amount);`  
		Reduces hit points by the given amount.
	- `void beRepaired(unsigned int amount);`  
		Increases hit points by the given amount. Costs 1 energy point.

## Exercise 01

This exercise builds upon the previous one by introducing inheritance.

- Create a class `ScavTrap` that inherits from `ClapTrap`:
- Add a new member function `void guardGate();` which prints a message indicating that the ScavTrap is now in Gatekeeper mode.
- Override the `attack()` function to print a different message than `ClapTrap`.

## Exercise 02

- Create a class `FragTrap` that inherits from `ClapTrap`.
- Add a new member function `void highFivesGuys();` which prints a high-five message.

## Exercise 03

This exercise introduces the concept of virtual inheritance and the diamond problem.

- Create a class `DiamondTrap` that inherits from both `ScavTrap` and `FragTrap`.
- Add a private attribute `name` (distinct from the `ClapTrap` name). The `ClapTrap::name` should get a `_clap_name` suffix.
- The `attack()` function and `energyPoints` attribute should be inherited from `ScavTrap`, while the rest of the attributes should come from `FragTrap`.
- Add a member function `void whoAmI();` which prints both its own name and the `ClapTrap` name.
