//NOLINTBEGIN(cppcoreguidelines-pro-bounds-constant-array-index)

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "../colors.hpp"
#include <iostream>

void test_subject(void)
{
	std::cout << BOLD "TEST FROM SUBJECT\n\n" RESET;
	
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Animal* k = new Animal();
	delete j;
	delete i;
	delete k;
}

void test_with_array(void)
{
	std::cout << BOLD "\nTEST FOR ARRAY\n\n" RESET;
	
	Animal *animals[10];
	for (int i = 0; i < 10; i++) {
		if (i < 5)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}
	for (int i = 0; i < 10; i++) {
		std::cout << BRIGHT_CYAN << animals[i]->getType() << " says: " RESET;
		animals[i]->makeSound();
	}
	for (int i = 0; i < 10; i++) {
		delete animals[i];
	}
}

void test_copies(void)
{
	std::cout << BOLD "\nTEST FOR COPIES\n\n" RESET;

	Cat cat = Cat();
	cat.think("What am I?");
	cat.think("Am I an animal?");
	cat.think("Am I a cat?");
	cat.think("Food");
	cat.think("I'm sleepy");
	std::cout << "\nOriginal cat's brain:\n";
	cat.printBrain();

	Cat cat2 = Cat(cat);
	std::cout << "\nCopy constructed cat's brain:\n";
	cat2.printBrain();
	cat2.think("I'm hungry again");

	std::cout << "Copy constructed cat's brain:\n";
	cat2.printBrain();
	std::cout << "Original cat's brain:\n";
	cat.printBrain();

	cat2 = cat;
	std::cout << "Copied cat's brain:\n";
	cat2.printBrain();
	cat.think("Mouse");
	std::cout << "Original cat's brain:\n";
	cat.printBrain();
	std::cout << "Copied cat's brain:\n";
	cat2.printBrain();
}
//NOLINTEND(cppcoreguidelines-pro-bounds-constant-array-index)
