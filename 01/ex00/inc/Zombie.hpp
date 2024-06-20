#pragma once

#include <string>
#include <iostream>

class Zombie {
	private:
		std::string	_name;
	public:
		Zombie(std::string name);
		~Zombie();
		void	announce();
};
