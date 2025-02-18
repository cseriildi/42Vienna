#ifndef MYEXCEPTION_HPP
#define MYEXCEPTION_HPP

#include <string>
#include <exception>

class MyException : public std::exception //NOLINT
{
	public:
		virtual ~MyException() throw();
		const char* what() const throw();

	protected:
		MyException(const std::string& msg);

	private:
		std::string _msg;	
};

#endif
