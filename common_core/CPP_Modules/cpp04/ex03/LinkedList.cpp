#include "LinkedList.hpp"
#include "AMateria.hpp"
#include <cstddef>
#include <new>

LinkedList::LinkedList() : _head(NULL) {}

LinkedList::~LinkedList() {clear();}

void LinkedList::add_new(void *new_node)
{
	AMateria *tmp = static_cast<AMateria*>(_head);

	if (tmp == NULL)
	{
		_head = new_node;
		return;
	}
	void *next = tmp->get_next();
	while (next != NULL)
	{
		tmp = static_cast<AMateria*>(next);
		next = tmp->get_next();
	}
	tmp->set_next(new_node);
}

void LinkedList::clear()
{
	AMateria *tmp = static_cast<AMateria*>(_head);
	AMateria *next = NULL;

	while (tmp != NULL)
	{
		next = static_cast<AMateria*>(tmp->get_next());
		::operator delete(tmp);
		tmp = next;
	}
	_head = NULL;
	
}

