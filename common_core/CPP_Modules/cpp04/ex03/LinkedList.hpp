#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

class LinkedList //NOLINT
{
	public:

		LinkedList();
		~LinkedList();

		void add_new(void *new_node);
		void clear();

	private:
		void* _head;
};

#endif
