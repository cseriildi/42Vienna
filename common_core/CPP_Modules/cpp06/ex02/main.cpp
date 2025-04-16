#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <iostream>
#include <new>

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main(void) try {
	Base* p = generate();
	identify(p);
	identify(*p);
	delete p;
	return 0;
} catch (const std::bad_alloc &e) {
	std::cerr << e.what() << "\n";
	return 1;
}
