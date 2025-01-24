//NOLINTBEGIN(cppcoreguidelines-init-variables)

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "LinkedList.hpp"
#include <iostream>

LinkedList g_head = LinkedList(); //NOLINT

int main()
{
	{
		std::cerr << "TEST FORM SUBJECT\n\n";

		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		
		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");

		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	{
		std::cerr << "\nTEST FOR DEEP COPIES IN CHARACTER\n\n";
		
		AMateria* ice = new Ice();
		AMateria* ice2 = ice;

		Character* bob = new Character("bob");
		bob->equip(ice);
		bob->equip(ice);
		bob->equip(ice2);

		bob->printInventory();

		Character* bob2 = new Character(*bob);
		bob2->printInventory();
		bob2->equip(new Cure());
		bob2->printInventory();
		bob2->unequip(0);

		bob->printInventory();
		bob2->printInventory();

		bob2->equip(new Ice());
		bob2->equip(new Cure());
		bob2->equip(new Cure());

		bob2->printInventory();

		bob2->equip(new Cure());

		*bob = *bob2;

		bob->printInventory();

		bob->unequip(0);

		bob->printInventory();
		bob2->printInventory();

		delete bob;
		delete bob2;
	}
	{
		std::cerr << "\nTEST FOR DEEP COPIES IN MATERIASOURCE\n\n";
		
		AMateria* ice = new Ice();

		MateriaSource* pda = new MateriaSource();
		pda->learnMateria(ice);
		pda->learnMateria(ice);
		pda->learnMateria(new Cure());

		pda->printInventory();

		MateriaSource* pda2 = new MateriaSource(*pda);
		pda2->printInventory();
		pda2->learnMateria(new Ice());
		pda2->printInventory();
		pda->printInventory();

		pda2->learnMateria(new Ice());


		*pda2 = *pda;

		pda2->printInventory();

		pda2->learnMateria(new Cure());

		pda2->printInventory();
		pda->printInventory();

		delete pda;
		delete pda2;
	}
	
}
//NOLINTEND(cppcoreguidelines-init-variables)
