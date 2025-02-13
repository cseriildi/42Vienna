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
	const WrongAnimal* k = new WrongCat();

	std::cout << BRIGHT_CYAN << meta->getType() << " says: " RESET;
	meta->makeSound();

	std::cout << BRIGHT_CYAN << i->getType() << " says: " RESET;
	i->makeSound();

	//since the makesound is not virtual the WrongAnimal::makesound() will be called
	std::cout << BRIGHT_CYAN << j->getType() << " says: " RESET;
	j->makeSound();
	std::cout << BRIGHT_CYAN << k->getType() << " says: " RESET;
	k->makeSound();

	//not polymorphic if destructor not virtual
	//dynamic_cast<const WrongCat*>(k)->makeSound();

	delete meta;
	delete i;

	//if destructor is not virtual the WrongCat destructor is not gonna get called.
	delete k;
}

void test_copies(void)
{
	std::cout << BOLD "\nTEST FOR COPIES\n\n" RESET;

	Animal *animal = new Animal();
	std::cout << BRIGHT_CYAN << animal->getType() << " says: " RESET;
	animal->makeSound();
	std::cout << "\n";

	Cat *cat = new Cat();
	std::cout << BRIGHT_CYAN << cat->getType() << " says: " RESET;
	cat->makeSound();
	std::cout << "\n";

	Animal *cat2 = new Cat(*cat);
	std::cout << BRIGHT_CYAN << cat2->getType() << " says: " RESET;
	cat2->makeSound();
	delete cat;
	delete cat2;
	std::cout << "\n";

	Dog *dog = new Dog();
	std::cout << BRIGHT_CYAN << dog->getType() << " says: " RESET;
	dog->makeSound();
	std::cout << "\n";

	Dog *dog3 = new Dog();
	*dog3 = *dog;
	std::cout << BRIGHT_CYAN << dog3->getType() << " says: " RESET;
	dog3->makeSound();
	delete dog3;
	std::cout << "\n";

	Animal *dog2 = new Dog(*dog);
	std::cout << BRIGHT_CYAN << dog2->getType() << " says: " RESET;
	dog2->makeSound();
	std::cout << "\n";

	//slicing
	*animal = *dog; //NOLINT
	std::cout << BRIGHT_CYAN << animal->getType() << " says: " RESET;
	animal->makeSound();
	delete dog;
	std::cout << "\n";

	//the animal is just an animal, the dog2 is an animal pointer to a dog
	//so eventhough the type gets copied the animal doesn't become a dog instance
	*animal = *dog2;
	std::cout << BRIGHT_CYAN << animal->getType() << " says: " RESET;
	animal->makeSound();
	delete dog2;
	delete animal;

}
