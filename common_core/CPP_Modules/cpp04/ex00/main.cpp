#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
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
	cat2.makeSound();
	cat3.makeSound();

	dog.makeSound();
	dog2.makeSound();
	dog3.makeSound();


	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* i2 = new WrongCat();
	std::cout << i2->getType() << " " << std::endl; //NOLINT
	i2->makeSound();
	meta2->makeSound();

	delete meta2;
	delete i2;
	
	WrongAnimal c = WrongAnimal();
   	WrongCat Wrongcat = WrongCat();

	WrongCat Wrongcat2 = WrongCat();

	WrongCat Wrongcat3 = WrongCat(Wrongcat);

	Wrongcat2 = Wrongcat;

	Wrongcat.makeSound();
	Wrongcat2.makeSound();
	Wrongcat3.makeSound();

    return 0;
}
