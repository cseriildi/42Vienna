#include <string>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap a = ClapTrap();
   	ClapTrap b = ClapTrap("Duck");
	FragTrap c = FragTrap();
	FragTrap d = FragTrap("Duck2");

	d.attack("Goose");
	d.printInfo();
	d.takeDamage(2);
    d.printInfo();
	d.highFivesGuys();
	d.printInfo();
	d.beRepaired(420);
	d.printInfo();
	d.takeDamage(42);
	d.printInfo();
	d.takeDamage(420);
	d.printInfo();
	d.takeDamage(420);
	d.printInfo();
	d.attack("Goose");
	d.printInfo();
	d.beRepaired(42);
	d.printInfo();
	d.attack("Goose");
	d.printInfo();
	d.highFivesGuys();
	d.printInfo();
    return 0;
}
