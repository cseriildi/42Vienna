#include "AMateria.hpp"
#include "LinkedList.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>
#include <cstddef>
#include <new>

extern LinkedList g_head; //NOLINT

AMateria::AMateria() : _isEquipped(false), _next(NULL) {}

AMateria::AMateria(const std::string& type): _type(type), _isEquipped(false), _next(NULL) {}

AMateria::AMateria(const AMateria& other): _type(other._type), _isEquipped(false), _next(NULL) {}

AMateria::~AMateria() {}

AMateria&	AMateria::operator=(const AMateria& other)
{
	//While assigning a Materia to another, copying the type doesn’t make sense.
	(void)other;
	return *this;
}

const std::string&	AMateria::getType() const {return _type;}

void	AMateria::use(ICharacter& target)
{
	std::cout << "* uses " << _type << " on " << target.getName() << " *\n";
}

bool AMateria::isEquipped() const {return _isEquipped;}

void AMateria::setEquipped(bool isEquipped) {_isEquipped = isEquipped;}

void* AMateria::operator new(std::size_t size) {
    void* ptr = ::operator new(size);
	g_head.add_new(ptr);
    return ptr;
}

void AMateria::operator delete(void* ptr) {
    (void)ptr;
}

void* AMateria::get_next() const {return _next;}

void AMateria::set_next(void* next) {_next = next;}
