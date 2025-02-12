#include "Animal.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "../colors.hpp"
#include <iostream>

void test_subject(void)
{
	std::cout << BOLD "TEST FROM SUBJECT\n\n" RESET;
	
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl; //NOLINT
	std::cout << i->getType() << " " << std::endl; //NOLINT
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
	delete j;
}

void test_wrong_animal(void)
{
	std::cout << BOLD "\nTEST FOR WRONG ANIMAL CLASS\n\n" RESET;
	
	const WrongAnimal* meta = new WrongAnimal();
	const WrongCat* i = new WrongCat();
	const WrongAnimal* j = i;
	std::cout << i->getType() << "\n";
	std::cout << j->getType() << "\n";
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
}

void test_copies(void)
{
	std::cout << BOLD "\nTEST FOR COPIES\n\n" RESET;

	Animal *animal = new Animal();
	animal->makeSound();

	Cat *cat = new Cat();
	cat->makeSound();
	Animal *cat2 = new Cat(*cat);
	cat2->makeSound();

	delete cat;
	delete cat2;

	Dog *dog = new Dog();
	dog->makeSound();
	Animal *dog2 = new Dog(*dog);
	dog2->makeSound();

	*animal = *dog2;
	animal->makeSound();
	Dog *dog3 = new Dog();
	*dog3 = *dog;
	dog3->makeSound();

	delete animal;
	delete dog;
	delete dog2;
	delete dog3;
}
