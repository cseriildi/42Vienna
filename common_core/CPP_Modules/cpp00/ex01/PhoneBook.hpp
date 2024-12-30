#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

class PhoneBook
{
	public:

		static const int	MAXCONTACTCOUNT = 8;
		static const int	BOXLENGTH = 10;
		
		//Constructor & Destructor
		PhoneBook();
		~PhoneBook();

		//Setters
		void	setContact(const std::wstring& firstName,
							const std::wstring& lastName,
							const std::wstring& nickName,
							const std::wstring& phoneNumber,
							const std::wstring& darkestSecret);

		//Getters
		int		getContactCount(void) const;
		Contact	getContact(int index) const;

		//Functions
		void	printPhonebook(void) const;
		void	printContact(int index) const;
		void	add_contact(void);
		void	search_contact(void) const;

	private:

		//Variables
		int		_contactCount;
		Contact	_contacts[MAXCONTACTCOUNT];

		//Functions
		void	_shiftContacts(void);
		
};

#endif
