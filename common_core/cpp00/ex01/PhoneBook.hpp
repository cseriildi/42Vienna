/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:14:48 by icseri            #+#    #+#             */
/*   Updated: 2024/09/06 16:04:06 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>

void	print_field(std::string field, int len);

class PhoneBook
{
	public:

		//Constructor & Destructor
		PhoneBook();
		~PhoneBook();

		//Setters
		void				set_contact(std::string first_name,
										std::string last_name,
										std::string nickname,
										std::string phone_number,
										std::string darkest_secret);

		//Getters
		int					get_contact_count(void);
		Contact				get_contact(int index);

		//Functions
		void				print_phonebook(void);
		void				print_contact(int index);

	private:

		//Variables
		static const int	max_contact_count = 8;
		static const int	box_length = 10;
		int					contact_count;
		Contact				contacts[max_contact_count];

		//Functions
		void				shift_contacts(void);
		
};

#endif