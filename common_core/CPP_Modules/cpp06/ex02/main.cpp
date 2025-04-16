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

	A* a = new A();
	identify(a);
	identify(*a);
	delete a;

	B* b = new B();
	identify(b);
	identify(*b);
	delete b;

	C* c = new C();
	identify(c);
	identify(*c);
	delete c;

	return 0;
} catch (const std::bad_alloc &e) {
	std::cerr << e.what() << "\n";
	return 1;
}
