#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

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

	protected:

		AMateria();

		const std::string _type; //NOLINT

};

#endif
