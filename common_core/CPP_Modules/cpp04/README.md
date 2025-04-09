# About the CPP Module 04 project

## Summary
The goal of the CPP Module projects is to get familiar with C++ programming language quickly. 
This project specifically focuses on `subtype polymorphism`, `abstract classes` and `interfaces`.

>**Allowed:** Any function from the standard library. If there is a C++ version of a function, use that. The code must compile with C++98.
>
>**Forbidden:** Any function from external libraries, as well as `*printf()`, `*alloc()` and `free()`. Containers (`vector`, `list`, `map`, ...) and algorithms (functions from the `algorithm` header).


## Useful Stuff
- [Pure virtual functions, abstract base classes, and interface classes](https://www.learncpp.com/cpp-tutorial/pure-virtual-functions-abstract-base-classes-and-interface-classes/)

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
- Create an abstract class `AMateria`:  
	```
	class AMateria
	{
		protected:
			[...]
		public:
			AMateria(std::string const & type);
			[...]
			std::string const & getType() const; //Returns the materia type
			virtual AMateria* clone() const = 0;
			virtual void use(ICharacter& target);
	};
	```
 
- Create the concrete `Ice` and `Cure` classes that inherit from `AMateria`:
    - The `clone()` function returns a new instance of the same type (`Ice` or `Cure`).
    - The `use()` function outputs:
        - **Ice**: `* shoots an ice bolt at <name> *`
        - **Cure**: `* heals <name>'s wounds *`
- Create the interface `ICharacter`:  
	```
	class ICharacter
	{
		public:
			virtual ~ICharacter() {}
			virtual std::string const & getName() const = 0;
			virtual void equip(AMateria* m) = 0;
			virtual void unequip(int idx) = 0;
			virtual void use(int idx, ICharacter& target) = 0;
	};
	```
- Create the `Character` class implementing `ICharacter`:
    - The character has an inventory of 4 Materia slots.
    - Ensure deep copy of the inventory when copying a `Character`.
    - Implement the `equip()`, `unequip()`, and `use()` methods.
- Create the interface `IMateriaSource`:
	```
	class IMateriaSource
	{
		public:
			virtual ~IMateriaSource() {}
			virtual void learnMateria(AMateria*) = 0;
			virtual AMateria* createMateria(std::string const & type) = 0;
	};
	```
- Create the `MateriaSource` class implementing `IMateriaSource`:
    - The `MateriaSource` can store up to 4 `Materia`s in the inventory.
	- `learnMateria(AMateria*)` copies a `Materia` into the inventory.
    - `createMateria(std::string const & type)` tries to find the `Materia` in the inventory based on the `type`, if found return a clone of it.
