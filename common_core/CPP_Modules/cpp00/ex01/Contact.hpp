//NOLINTFILE

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	public:
	
		//Constructor & Destructor
		Contact();
		~Contact();

		//Setters
		void	setFirstName(const std::wstring& firstName);
		void	setLastName(const std::wstring& lastName);
		void	setNickname(const std::wstring& nickname);
		void	setPhoneNumber(const std::wstring& phoneNumber);
		void	setDarkestSecret(const std::wstring& darkestSecret);
		
		//Getters
		const std::wstring&	getFirstName() const;
		const std::wstring&	getLastName() const;
		const std::wstring&	getNickname() const;
		const std::wstring&	getPhoneNumber() const;
		const std::wstring&	getDarkestSecret() const;

	private:

		//Variables
		std::wstring	_firstName;
		std::wstring	_lastName;
		std::wstring	_nickname;
		std::wstring	_phoneNumber;
		std::wstring	_darkestSecret;
		
};

#endif
