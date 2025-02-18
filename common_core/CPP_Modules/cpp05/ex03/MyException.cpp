#include "MyException.hpp"
#include <string>

MyException::MyException(const std::string& msg) : _msg(msg) {}

MyException::~MyException() throw() {}

const char* MyException::what() const throw() {return _msg.c_str();}
