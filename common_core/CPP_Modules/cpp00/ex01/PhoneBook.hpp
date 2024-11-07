/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:14:48 by icseri            #+#    #+#             */
/*   Updated: 2024/11/07 15:23:11 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

void		print_field(const std::string& field, int len);
std::string	ft_itoa(int n);

class PhoneBook
{
	public:

		static const int	MAXCONTACTCOUNT = 8;
		static const int	BOXLENGTH = 10;
		
		//Constructor & Destructor
		PhoneBook();
		~PhoneBook();

		//Setters
		void				setContact(const std::string& firstName,
										const std::string& lastName,
										const std::string& nickName,
										const std::string& phoneNumber,
										const std::string& darkestSecret);

		//Getters
		int					getContactCount(void) const;
		Contact				getContact(int index) const;

		//Functions
		void				printPhonebook(void) const;
		void				printContact(int index) const;

	private:

		//Variables
		int					_contactCount;
		Contact				_contacts[MAXCONTACTCOUNT];

		//Functions
		void				_shiftContacts(void);
		
};

#endif
