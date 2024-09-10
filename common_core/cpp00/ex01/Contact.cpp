/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:09:58 by cseriildii        #+#    #+#             */
/*   Updated: 2024/09/10 11:29:20 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

void	Contact::setFirstName(const std::string& firstName) {this->_firstName = firstName;}
void	Contact::setLastName(const std::string& lastName) {this->_lastName = lastName;}
void	Contact::setNickname(const std::string& nickname) {this->_nickname = nickname;}
void	Contact::setPhoneNumber(const std::string& phoneNumber) {this->_phoneNumber = phoneNumber;}
void	Contact::setDarkestSecret(const std::string& darkestSecret) {this->_darkestSecret = darkestSecret;}

const std::string&	Contact::getFirstName(void) const {return this->_firstName;}
const std::string&	Contact::getLastName(void) const {return this->_lastName;}
const std::string& Contact::getNickname(void) const {return this->_nickname;}
const std::string& Contact::getPhoneNumber(void) const {return this->_phoneNumber;}
const std::string& Contact::getDarkestSecret(void) const {return this->_darkestSecret;}
