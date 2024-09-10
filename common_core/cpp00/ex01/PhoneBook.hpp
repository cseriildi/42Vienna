/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:14:48 by icseri            #+#    #+#             */
/*   Updated: 2024/09/10 10:09:31 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>

void		print_field(const std::string& field, int len);
std::string	ft_itoa(int n);

class PhoneBook
{
	public:

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
		static const int	_MaxContactCount = 8;
		static const int	_BoxLength = 10;
		int					_contactCount;
		Contact				_contacts[_MaxContactCount];

		//Functions
		void				_shiftContacts(void);
		
};

#endif