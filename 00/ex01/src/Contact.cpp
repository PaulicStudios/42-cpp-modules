#include "../inc/Contact.hpp"
#include <iostream>
#include <ostream>
#include <string>

Contact::Contact()
{
	Contact::_first_name = std::string();
	Contact::_last_name = std::string();
	Contact::_nickname = std::string();
	Contact::_phone_number = std::string();
	Contact::_darkest_secret = std::string();
}

Contact::~Contact() {}

void Contact::fill_contact(std::string first_name, std::string last_name,
						std::string nickname, std::string phone_number,
						std::string darkest_secret)
{
	_first_name = first_name;
	_last_name = last_name;
	_nickname = nickname;
	_phone_number = phone_number;
	_darkest_secret = darkest_secret;
}

void	Contact::print_contact()
{
	if (_first_name.empty())
		return;
	std::cout << "first name: " << _first_name << std::endl;
	std::cout << "last name: " << _last_name << std::endl;
	std::cout << "nickname: " << _nickname << std::endl;
	std::cout << "phone number: " << _phone_number << std::endl;
	std::cout << "darkest secret: " << _darkest_secret << std::endl;
}

void	printStr(std::string str)
{
	size_t	len;

	len = str.length();
	if (len == 10)
		std::cout << str.substr(0, 10);
	else if (len > 10)
	{
		std::cout << str.substr(0, 9) << ".";
	}
	else if (len < 10)
	{
		std::cout << str;
		while (len > 0)
		{
			std::cout << " ";
			len--;
		}
	}
}

void	Contact::print_contact_row()
{
	if (_first_name.empty())
		return;
	printStr(_first_name);
	std::cout << "|";
	printStr(_last_name);
	std::cout << "|";
	printStr(_nickname);
}
