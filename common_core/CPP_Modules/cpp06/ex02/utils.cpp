//NOLINTBEGIN(readability-magic-numbers, cppcoreguidelines-pro-bounds-array-to-pointer-decay)
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstddef>
#include <ctime>
#include <fstream>
#include <iostream>

unsigned int random_num(void);

Base* generate(void)
{
	switch (random_num() % 3) {
	case 0: 
		return new A;
	case 1:
		return new B;
	case 2:
		return new C;
	default:
		return NULL;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
	{
		std::cout << "A object\n";
	}
	else if (dynamic_cast<B*>(p) != NULL)
	{
		std::cout << "B object\n";
	}
	else if (dynamic_cast<C*>(p) != NULL)
	{
		std::cout << "C object\n";
	}
	else
	{
		std::cout << "Unknown object\n";
	}
}

void identify(Base& p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A object\n";
	} catch (...) {
		try {
			(void)dynamic_cast<B&>(p);
			std::cout << "B object\n";
		} catch (...) {
			try {
				(void)dynamic_cast<C&>(p);
				std::cout << "C object\n";
			} catch (...) {
				std::cout << "Unknown object\n";
			}
		}
	}
}

unsigned int random_num(void)
{
	std::ifstream urandom("/dev/urandom", std::ios::in | std::ios::binary);
	if (!urandom)
		return clock();

	char random_bytes[10];
	urandom.read(random_bytes, sizeof(random_bytes));

	if (!urandom)
		return clock();
	return static_cast<unsigned int>(random_bytes[0]);
}
//NOLINTEND(readability-magic-numbers, cppcoreguidelines-pro-bounds-array-to-pointer-decay)
