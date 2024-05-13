#include "Contact.hpp"

class PhoneBook {
	private:
		Contact			_contacts[8];
		unsigned char	_ind;
	public:
		PhoneBook();
		~PhoneBook();
		void add_Contact(std::string first_name, std::string last_name,
							std::string nickname, std::string phone_number,
							std::string darkest_secret);
		void print_Contacts();
		void print_Contact(int ind);
};