#include <iostream>

int main(int argc, char **args)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int ind_arg = 1; ind_arg < argc; ind_arg++)
		for (int ind_str = 0; args[ind_arg][ind_str]; ind_str++)
			std::cout << (char) std::toupper(args[ind_arg][ind_str]);
	std::cout << std::endl;
}
