#include "../inc/PhoneBook.hpp"

int	main()
{
	PhoneBook phoneBook = PhoneBook();

	phoneBook.add_Contact("first name", "last name", "nickname", "phone number", "darkest secret");
	phoneBook.print_Contacts();
}