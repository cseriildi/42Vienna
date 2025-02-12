#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "LinkedList.hpp"
#include "colors.hpp"
#include <iostream>

extern LinkedList g_head;

void test_subject(void)
{
	std::cout << BOLD "TEST FORM SUBJECT\n\n" RESET;

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

void test_materias(void)
{
	std::cout << BOLD "\nTEST FOR MATERIAS\n\n" RESET;

	Character* bob = new Character("bob");
	Character* bobby = new Character("bobby");


	AMateria* ice = new Ice();
	AMateria* ice2 = new Ice(*dynamic_cast<const Ice*>(ice));
	*ice = *ice2;

	AMateria* cure = new Cure();
	AMateria* cure2 = new Cure(*dynamic_cast<const Cure*>(cure));
	*cure = *cure2;

	bob->equip(ice);
	bob->equip(ice);

	bobby->equip(ice);
	bob->unequip(0);
	bobby->equip(ice);
	bobby->equip(ice2);


	bob->equip(cure);
	bob->equip(cure);

	bobby->equip(cure);
	bob->unequip(0);
	bobby->equip(cure);
	bobby->equip(cure2);

	bob->printInventory();
	bobby->printInventory();

	AMateria* ice3 = ice->clone();
	AMateria* cure3 = cure->clone();

	ice3->use(*bob);
	cure3->use(*bobby);

	delete bob;
	delete bobby;
}

void test_characters(void)
{
	std::cout << BOLD "\nTEST FOR CHARACTERS\n\n" RESET;
	
	Character* duck = new Character("Bob");

	duck->unequip(0);
	duck->unequip(-1);
	duck->unequip(4);
	duck->equip(NULL);
	
	duck->equip(new Ice());
	duck->equip(new Cure());
	duck->equip(new Cure());
	duck->equip(new Ice());
	duck->equip(new Ice());

	duck->printInventory();

	Character* ducky = new Character(*duck);
	std::cout << "Duck is called " BOLD << duck->getName() << RESET " and ducky is also called " BOLD << ducky->getName();
	std::cout << RESET " because ducky is a copy of duck, so lets change ducky's name to avoid confusion.\n";

	ducky->setName("Bobby");
	ducky->printInventory();
	ducky->unequip(0);
	ducky->unequip(2);
	ducky->equip(new Cure());

	ducky->printInventory();
	duck->printInventory();

	*ducky = *duck;

	std::cout << "Ducky copied duck again so his name changed back to " BOLD << duck->getName() << RESET " let's change it again.\n";
	ducky->setName("Bobby");

	ducky->printInventory();

	duck->unequip(0);

	duck->printInventory();
	ducky->printInventory();

	std::cout << "Now Bob is going to try to use materias with index between -1 and 4.\n";
	for (int i = -1; i < 5; i++	) {
		duck->use(i, *ducky);
	}

	delete duck;
	delete ducky;
}

void test_materiasources(void)
{
	std::cout << BOLD "\nTEST FOR MATERIASOURCES\n\n" RESET;
	
	MateriaSource* pda = new MateriaSource();

	AMateria* duckshit = pda->createMateria("duckshit");
	pda->learnMateria(duckshit);

	pda->learnMateria(new Ice());
	AMateria* ice = pda->createMateria("ice");

	pda->learnMateria(ice);
	pda->learnMateria(new Cure());
	AMateria* cure = pda->createMateria("cure");

	pda->printInventory();

	MateriaSource* pda2 = new MateriaSource(*pda);
	std::cout << "Copy constructed MateriaSource:";
	pda2->printInventory();
	pda2->learnMateria(ice);
	pda2->learnMateria(cure);
	pda2->printInventory();
	std::cout << "Original MateriaSource:";
	pda->printInventory();

	*pda2 = *pda;
	std::cout << "Copied MateriaSource:";
	pda2->printInventory();

	pda2->learnMateria(cure);

	pda2->printInventory();

	std::cout << "Original MateriaSource:";
	pda->printInventory();

	delete pda;
	delete pda2;
}
