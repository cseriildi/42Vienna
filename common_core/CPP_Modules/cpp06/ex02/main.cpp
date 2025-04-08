#include "Base.hpp"
#include <iostream>
#include <new>

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main(void)
{
	try {
		Base* p = generate();
		identify(p);
		identify(*p);
		delete p;
	} catch (const std::bad_alloc&) {
		std::cerr << "New failed\n";
		return 1;
	}
	return 0;
}
