//NOLINTBEGIN(bugprone-easily-swappable-parameters, cppcoreguidelines-pro-bounds-constant-array-index, readability-magic-numbers, cppcoreguidelines-avoid-magic-numbers)

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "utils.hpp"
#include <iostream>
#include <string>

PhoneBook::PhoneBook() : _contactCount(0) {}
PhoneBook::~PhoneBook() {}

void	PhoneBook::setContact(const std::wstring& firstName,
								const std::wstring& lastName,
								const std::wstring& nickname,
								const std::wstring& phoneNumber,
								const std::wstring& darkestSecret)
{
	Contact contact;
	
	contact.setFirstName(firstName);
	contact.setLastName(lastName);
	contact.setNickname(nickname);
	contact.setPhoneNumber(phoneNumber);
	contact.setDarkestSecret(darkestSecret);

	_shiftContacts();
	this->_contacts[0] = contact;
	if (this->_contactCount < PhoneBook::MAXCONTACTCOUNT)
		this->_contactCount++;
}
int		PhoneBook::getContactCount(void) const {return this->_contactCount;}
Contact	PhoneBook::getContact(int index) const {return this->_contacts[index];}

void	PhoneBook::_shiftContacts(void)
{
	for (int i = PhoneBook::MAXCONTACTCOUNT - 1; i > 0; i--)
		this->_contacts[i] = this->_contacts[i - 1];
}

void	PhoneBook::printContact(int index) const
{
	Contact contact;

	contact = getContact(index);
	std::wcout << "First Name: " << contact.getFirstName() << "\n";
	std::wcout << "Last Name: " << contact.getLastName() << "\n";
	std::wcout << "Nickname: " << contact.getNickname() << "\n";
	std::wcout << "Phone Number: " << contact.getPhoneNumber() << "\n";
	std::wcout << "Darkest Secret: " << contact.getDarkestSecret() << "\n";
}

void	PhoneBook::printPhonebook(void) const
{
	std::wcout << "|";
	print_field(L"Index", PhoneBook::BOXLENGTH);
	std::wcout << "|";
	print_field(L"First Name", PhoneBook::BOXLENGTH);
	std::wcout << "|";
	print_field(L"Last Name", PhoneBook::BOXLENGTH);
	std::wcout << "|";
	print_field(L"Nickname", PhoneBook::BOXLENGTH);
	std::wcout << "|\n";

	for (int i = 0; i < 4 * PhoneBook::BOXLENGTH + 5; i++)
		std::wcout << "-";
	std::wcout << "\n";
	for (int i = 0; i < this->_contactCount; i++)
	{
		std::wcout << "|";
		print_field(ft_itoa(i), PhoneBook::BOXLENGTH);
		std::wcout << "|";
		print_field(this->_contacts[i].getFirstName(), PhoneBook::BOXLENGTH);
		std::wcout << "|";
		print_field(this->_contacts[i].getLastName(), PhoneBook::BOXLENGTH);
		std::wcout << "|";
		print_field(this->_contacts[i].getNickname(), PhoneBook::BOXLENGTH);
		std::wcout << "|" << "\n";
		for (int i = 0; i < 4 * PhoneBook::BOXLENGTH + 5; i++)
			std::wcout << "-";
		std::wcout << "\n";
	}
}

void	PhoneBook::add_contact()
{
	std::wstring firstName = get_data(L"First Name");
	std::wstring lastName = get_data(L"Last Name");
	std::wstring nickname = get_data(L"Nickname");
	std::wstring phoneNumber = get_data(L"Phone Number");
	std::wstring darkestSecret = get_data(L"Darkest Secret");

	this->setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
}

void	PhoneBook::search_contact() const
{
	int 		index = 0;
	int			max_index = this->getContactCount();

	if (max_index == 0)
	{
		std::wcerr << "There are no contacts in the phonebook\n";
		return;
	}
	this->printPhonebook();
	
	while (true)
	{
		index = get_index();
	
		if (index < max_index && index >= 0)
			break;
		if (index < 0)
			std::wcerr << "Index cannot be negative!\n";
		else if (max_index == 1)
			std::wcerr << "There is only 1 contact in the phonebook\n";
		else
			std::wcerr << "There are only " << max_index << " contacts in the phonebook\n";
	}
	this->printContact(index);
}

//NOLINTEND(bugprone-easily-swappable-parameters, cppcoreguidelines-pro-bounds-constant-array-index, readability-magic-numbers, cppcoreguidelines-avoid-magic-numbers)
