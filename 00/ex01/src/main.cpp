#include "../inc/PhoneBook.hpp"

bool	get_input(std::string &input)
{
	while (true)
	{
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (false);
		if (input.empty())
		{
			std::cout << "Input cannot be empty" << std::endl;
			continue;
		}
		break;
	}
	return (true);
}

void	add_contact(PhoneBook &phoneBook)
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	std::cout << "Enter first name: ";
	if (!get_input(first_name))
		return;
	std::cout << "Enter last name: ";
	if (!get_input(last_name))
		return;
	std::cout << "Enter nickname: ";
	if (!get_input(nickname))
		return;
	std::cout << "Enter phone number: ";
	if (!get_input(phone_number))
		return;
	std::cout << "Enter darkest secret: ";
	if (!get_input(darkest_secret))
		return;
	phoneBook.add_Contact(first_name, last_name, nickname, phone_number, darkest_secret);
	std::cout << "Contact added" << std::endl;
}

void	search_contact(PhoneBook &phoneBook)
{
	std::string index;

	if (phoneBook.empty())
	{
		std::cout << "No contacts" << std::endl;
		return;
	}
	phoneBook.print_Contacts();
	while (true)
	{
		std::cout << "Enter index: ";
		std::getline(std::cin, index);
		if (std::cin.eof())
			break;
		if (index.length() == 1 && index[0] >= '0' && index[0] <= '7')
		{
			if (phoneBook.print_Contact(index[0] - '0'))
				break;
		}
		std::cout << "Invalid index" << std::endl;
	}
}

int	main()
{
	PhoneBook phoneBook = PhoneBook();
	std::string command;

	while (!std::cin.eof())
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, command);
		if (command == "EXIT" || std::cin.eof())
			break;
		else if (command == "ADD")
			add_contact(phoneBook);
		else if (command == "SEARCH")
			search_contact(phoneBook);
		else
		{
			std::cout << "Invalid command" << std::endl;
			std::cout << "Valid commands: ADD, SEARCH, EXIT" << std::endl;
		}
	}
}