#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void fill_array(Animal **animals)
{
	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}
}

void free_array(Animal **animals)
{
	for (int i = 0; i < 10; i++)
	{
		delete animals[i];
	}
}

void sound_array(Animal **animals)
{
	for (int i = 0; i < 10; i++)
	{
		animals[i]->makeSound();
	}
}

int main()
{
    const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	Animal *animals[10];
	fill_array(animals);
	sound_array(animals);
	free_array(animals);

	

    return 0;
}
