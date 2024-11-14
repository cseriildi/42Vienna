#include <string>
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap c = DiamondTrap();
	c.whoAmI();
	DiamondTrap d = DiamondTrap("Duck2");
	d.whoAmI(); 
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
