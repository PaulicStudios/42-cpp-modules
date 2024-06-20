#include <string>
#include <iostream>

int	main(void)
{
	std::string		string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << "Address in memory of the string:	" << &string << std::endl;
	std::cout << "Address in memory of the stringPTR:	" << stringPTR << std::endl;
	std::cout << "Address in memory of the stringREF:	" << &stringREF << std::endl;

	std::cout << "Value of string:	" << string << std::endl;
	std::cout << "Value of stringPTR:	" << *stringPTR << std::endl;
	std::cout << "Value of stringREF:	" << stringREF << std::endl;
}
