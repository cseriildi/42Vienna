#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}


Base * generate(void) {

	//randomly return A, B or C
	return new A;
}

void identify(Base* p) {

}

void identify(Base& p) {

}