#include "../inc/PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	_ind = 0;
}

PhoneBook::~PhoneBook() {}

bool	PhoneBook::empty()
{
	return (_contacts[0].empty());
}

void	PhoneBook::add_Contact(std::string first_name, std::string last_name,
						std::string nickname, std::string phone_number,
						std::string darkest_secret)
{
	_contacts[_ind].fill_contact(first_name, last_name, nickname, phone_number, darkest_secret);
	_ind++;
	if (_ind > 8)
		_ind = 0;
}

void	PhoneBook::print_Contacts()
{
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	for (int ind = 0; ind < 8; ind ++)
	{
		if (_contacts[ind].empty())
			break;
		std::cout << "         " << ind << "|";
		_contacts[ind].print_contact_row();
	}
}

bool	PhoneBook::print_Contact(int ind)
{
	if (ind < 0 || ind > 7 || _contacts[ind].empty())
		return (false);
	_contacts[ind].print_contact();
	return (true);
}
