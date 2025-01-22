#include "LinkedList.hpp"
#include "Node.hpp"
#include <cstddef>
#include <new>

LinkedList::LinkedList() : _head(NULL) {}

LinkedList::~LinkedList() {clear();}

void LinkedList::add_new(void *new_node)
{
	Node *tmp = static_cast<Node*>(_head);

	if (tmp == NULL)
	{
		_head = new_node;
		return;
	}
	void *next = tmp->get_next();
	while (next != NULL)
	{
		tmp = static_cast<Node*>(next);
		next = tmp->get_next();
	}
	tmp->set_next(new_node);
}

void LinkedList::clear()
{
	Node *tmp = static_cast<Node*>(_head);
	Node *next = NULL;

	while (tmp != NULL)
	{
		next = static_cast<Node*>(tmp->get_next());
		::operator delete(tmp);
		tmp = next;
	}
	
}

