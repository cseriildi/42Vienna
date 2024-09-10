/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:03:02 by cseriildii        #+#    #+#             */
/*   Updated: 2024/09/10 11:31:19 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>

class Contact
{
	public:
	
		//Constructor & Destructor
		Contact();
		~Contact();

		//Setters
		void		setFirstName(const std::string& firstName);
		void		setLastName(const std::string& lastName);
		void		setNickname(const std::string& nickname);
		void		setPhoneNumber(const std::string& phoneNumber);
		void		setDarkestSecret(const std::string& darkestSecret);
		
		//Getters
		const std::string&	getFirstName() const;
		const std::string&	getLastName() const;
		const std::string&	getNickname() const;
		const std::string&	getPhoneNumber() const;
		const std::string&	getDarkestSecret() const;

	private:

		//Variables
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
		
};

#endif