#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <cstddef>

class ICharacter;

class AMateria
{	
	public:

		AMateria(std::string const & type);
		AMateria(const AMateria& other); 
		AMateria&	operator=(const AMateria& other);
		virtual ~AMateria();

		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

		void* operator new(std::size_t size);
		void operator delete(void* ptr);

		void *get_next() const;
		void set_next(void *next);

		bool isEquipped() const;
		void setEquipped(bool isEquipped);

	protected:

		AMateria();

		const std::string	_type; //NOLINT
		bool				_isEquipped; //NOLINT
		void				*_next; //NOLINT
		
};

#endif
