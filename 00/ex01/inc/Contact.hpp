#include <string>
#include <iostream>
#include <ostream>

class Contact
{
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;
	public:
		Contact();
		~Contact();
		void		fill_contact(std::string first_name, std::string last_name,
								std::string nickname, std::string phone_number,
								std::string darkest_secret);
		bool		empty();
		void		print_contact();
		void		print_contact_row();
};