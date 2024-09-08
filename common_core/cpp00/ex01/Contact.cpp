/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:09:58 by cseriildii        #+#    #+#             */
/*   Updated: 2024/09/08 16:28:22 by cseriildii       ###   ########.fr       */
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

std::string	Contact::getFirstName(void) const {return this->_firstName;}
std::string	Contact::getLastName(void) const {return this->_lastName;}
std::string Contact::getNickname(void) const {return this->_nickname;}
std::string Contact::getPhoneNumber(void) const {return this->_phoneNumber;}
std::string Contact::getDarkestSecret(void) const {return this->_darkestSecret;}
