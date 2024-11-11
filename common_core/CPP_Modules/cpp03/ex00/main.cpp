//NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)

#include <string>
#include "ClapTrap.hpp"

int main()
{
    ClapTrap a = ClapTrap();
    ClapTrap b = ClapTrap("Duck");

	b.attack("Goose");
	b.printInfo();
	b.takeDamage(2);
    b.printInfo();
	b.beRepaired(420);
	b.printInfo();
	b.takeDamage(42);
	b.printInfo();
	b.takeDamage(42);
	b.printInfo();
	b.takeDamage(420);
	b.printInfo();
	b.attack("Goose");
	b.printInfo();
	b.beRepaired(42);
	b.printInfo();
	b.attack("Goose");
	b.printInfo();
    return 0;
}

//NOLINTEND(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)
