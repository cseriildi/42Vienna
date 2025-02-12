# About the CPP Module 04 project

## Summary
The goal of the CPP Module projects is to get familiar with C++ programming language quickly. To learn about subtype polymorphism, abstract classes and interfaces.
- **Allowed functions**: Any function from the standard library, if there is a C++ version of the function, use that. The code must compile with c++98.
- **Forbidden functions**: Any function from external libraries and `*printf()`, `*alloc()` and `free()`. Namespace and friend keyword. `Containers` (vector/list/map/...) and `Algorithms` (functions from the `algorithm` header).

## Useful Stuff

## Exercise 00
- Create class `Animal` with:
	- `protected` variable `std::string type`
	- `public` members function `makeSound()`
- Implement `Dog` and `Cat` class from `Animal` class
- Override the `makeSound()` function so it prints the sound the specific animal makes
- Implement `WrongAnimal` and `WrongCat` classes to show why do we use virtual functions in the `Animal` class
- Print messages in the functions so you can identify when they get called.
- Write thorough test cases

## Exercise 01
- Create `Brain` class with a 100 element string array called `ideas`
- Add brains to the `Cat` and `Dog` classes. When they are constructed create a `new Brain()`, when destructing `delete` it.
- Make sure when copying Cats and Dogs the coppy is deep.
- Create an array of `Animal`s, fill half of it with `Cat`s the other half with `Dog`s.
- Write thorough test cases

## Exercise 02
- Now make the `Animal` class abstract, the base class should not be instantiable

## Exercise 03
