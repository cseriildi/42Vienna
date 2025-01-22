#ifndef NODE_HPP
#define NODE_HPP

#include <cstddef>

class Node //NOLINT
{
	public:
		virtual ~Node();
		Node();

		void* operator new(std::size_t size);
		void operator delete(void* ptr);

		void *get_next() const;
		void set_next(void *next);

		
	protected:

		void *_next; //NOLINT
};

#endif
