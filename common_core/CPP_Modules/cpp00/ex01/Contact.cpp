#include "Contact.hpp"
# include <string>

Contact::Contact() {}
Contact::~Contact() {}

void	Contact::setFirstName(const std::wstring& firstName) {this->_firstName = firstName;}
void	Contact::setLastName(const std::wstring& lastName) {this->_lastName = lastName;}
void	Contact::setNickname(const std::wstring& nickname) {this->_nickname = nickname;}
void	Contact::setPhoneNumber(const std::wstring& phoneNumber) {this->_phoneNumber = phoneNumber;}
void	Contact::setDarkestSecret(const std::wstring& darkestSecret) {this->_darkestSecret = darkestSecret;}

const std::wstring&	Contact::getFirstName(void) const {return this->_firstName;}
const std::wstring&	Contact::getLastName(void) const {return this->_lastName;}
const std::wstring& Contact::getNickname(void) const {return this->_nickname;}
const std::wstring& Contact::getPhoneNumber(void) const {return this->_phoneNumber;}
const std::wstring& Contact::getDarkestSecret(void) const {return this->_darkestSecret;}
