#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <string>

class AAnimal
{
	public:

		virtual ~AAnimal(); 

		virtual void makeSound() = 0;

		const std::string&	getType() const;

	protected:
		AAnimal();
		AAnimal(const std::string& type);
		AAnimal(const AAnimal& other);
		AAnimal&	operator=(const AAnimal& other);
		

		std::string		_type; //NOLINT
};

#endif
