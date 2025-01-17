#include <string>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap a = FragTrap();
	FragTrap b = FragTrap("Duck");
	FragTrap c = FragTrap("Duck2");
	ClapTrap *d = &c;

	b.attack("Goose");
	b.printInfo();
	b.takeDamage(2);
    b.printInfo();
	b.highFivesGuys();
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
	b.highFivesGuys();
	b.printInfo();

	d->attack("Goose");
	d->takeDamage(42);
	d->beRepaired(42);
	//d->highFivesGuys(); this is only defined in FragTrap
    return 0;
}
