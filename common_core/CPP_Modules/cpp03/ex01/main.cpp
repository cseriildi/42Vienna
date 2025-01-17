//NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)

#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap a = ScavTrap();
	ScavTrap b = ScavTrap("Duck");
	ScavTrap c = ScavTrap("Duck2");
   	ClapTrap *d = &c;

	b.attack("Goose");
	b.printInfo();
	b.takeDamage(2);
    b.printInfo();
	b.guardGate();
	b.printInfo();
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
	b.guardGate();
	b.printInfo();

	d->attack("Goose");
	d->takeDamage(42);
	d->beRepaired(42);
	//d->guardGate(); //this is only defined in ScavTrap

    return 0;
}

//NOLINTEND(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)
