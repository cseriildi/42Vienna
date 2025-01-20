#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int main()
{
	{
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
	{
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
	/* {
		Animal *animal = new Animal();
		Dog *dog = new Dog();
		Cat *cat = new Cat();

		Animal *dog2 = new Dog(*dog);
		Animal *cat2 = new Cat(*cat);

		animal->makeSound();
		dog->makeSound();
		cat->makeSound();
		dog2->makeSound();
		cat2->makeSound();

		animal = dog;
		animal->makeSound();
		animal = cat;
		animal->makeSound();

		delete animal;
		delete dog;
		delete cat;
		delete dog2;
		delete cat2;
	} */
}
