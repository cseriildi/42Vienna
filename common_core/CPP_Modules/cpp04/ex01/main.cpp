//NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers, cppcoreguidelines-pro-bounds-constant-array-index)

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		const Animal* k = new Animal();
		delete j;
		delete i;
		delete k;
	}
	{
		Animal *animals[10];
		for (int i = 0; i < 10; i++) {
			if (i < 5)
				animals[i] = new Cat();
			else
				animals[i] = new Dog();
		}
		for (int i = 0; i < 10; i++) {
			animals[i]->makeSound();
		}
		for (int i = 0; i < 10; i++) {
			delete animals[i];
		}
	}
	{
		Cat cat = Cat();
		cat.think("What am I?");
		cat.think("Am I an animal?");
		cat.think("Am I an cat?");
		cat.think("Food");
		cat.think("I'm sleepy");
		cat.printBrain();

		Cat cat2 = Cat(cat);
		cat2.printBrain();
		cat2.think("I'm hungry again");
		cat2.printBrain();
		cat.printBrain();

		Cat cat3 = Cat();
		cat3.printBrain();
		cat3 = cat2;
		cat3.printBrain();
		cat3.think("Mouse");
		cat2.printBrain();
	}
}

//NOLINTEND(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers, cppcoreguidelines-pro-bounds-constant-array-index)
