#include "LinkedList.hpp"
#include "Node.hpp"
#include <cstddef>
#include <new>

extern LinkedList g_head; //NOLINT

Node::Node() : _next(NULL) {}

Node::~Node() {}

void* Node::operator new(std::size_t size) {
    void* ptr = ::operator new(size);
	g_head.add_new(ptr);
    return ptr;
}

void Node::operator delete(void* ptr) {
    (void)ptr;
}

void* Node::get_next() const {return _next;}

void Node::set_next(void* next) {_next = next;}
