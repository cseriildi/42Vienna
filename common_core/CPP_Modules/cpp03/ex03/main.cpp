#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
	{
		std::cout << "TEST1:"<<"\n";

		DiamondTrap a = DiamondTrap();

		std::cout << "\n";
		a.whoAmI();
		std::cout << "\n";
	}
	{
		std::cout << "\nTEST2:"<<"\n";

		DiamondTrap b = DiamondTrap("Duck");

		std::cout << "\n";

		b.whoAmI(); 
		b.attack("Goose");
		b.printInfo();
		b.takeDamage(2);
		b.printInfo();
		b.highFivesGuys();
		b.guardGate();
		b.beRepaired(420);
		b.printInfo();
		b.takeDamage(42);
		b.printInfo();
		b.takeDamage(420);
		b.printInfo();
		b.takeDamage(420);
		b.printInfo();
		b.attack("Goose");
		b.printInfo();
		b.beRepaired(42);
		b.printInfo();
		b.attack("Goose");
		b.printInfo();
		b.highFivesGuys();
		b.guardGate();

		std::cout << "\n";
	}
	{
		std::cout << "\nTEST3:"<<"\n";

		DiamondTrap a = DiamondTrap("Duck2");
		ClapTrap *b = &a;
		ScavTrap *c = &a;
		FragTrap *d = &a;

		std::cout << "\n";

		a.attack("Goose");
		b->attack("Goose");
		c->attack("Goose");
		d->attack("Goose");

		a.guardGate();
		//b->guardGate(); // only defined on ScavTrap
		c->guardGate();
		//d->guardGate();  // only defined on ScavTrap

		a.highFivesGuys();
		//b->highFivesGuys(); // only defined on FragTrap
		//c->highFivesGuys(); // only defined on FragTrap
		d->highFivesGuys();

		a.whoAmI();
		//b->whoAmI(); // only defined on DiamondTrap
		//c->whoAmI(); // only defined on DiamondTrap
		//d->whoAmI(); // only defined on DiamondTrap

		std::cout << "\n";
	}
    return 0;
}
