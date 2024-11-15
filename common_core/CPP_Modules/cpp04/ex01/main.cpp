#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
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
	
	Animal a = Animal();
   	Cat cat = Cat();
	Dog dog = Dog();

	Cat cat2 = Cat();
	Dog dog2 = Dog();

	Cat cat3 = Cat(cat);
	Dog dog3 = Dog(dog);

	cat2 = cat;
	dog2 = dog;

	cat.makeSound();
	dog.makeSound();

	cat2.makeSound();
	dog2.makeSound();

	cat3.makeSound();
	dog3.makeSound();

    return 0;
}
