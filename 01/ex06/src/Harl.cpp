/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:50:39 by pgrossma          #+#    #+#             */
/*   Updated: 2024/06/20 19:20:36 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
	_levels.insert(std::pair<std::string, void (Harl::*)(void)>("DEBUG", &Harl::_debug));
	_levels.insert(std::pair<std::string, void (Harl::*)(void)>("INFO", &Harl::_info));
	_levels.insert(std::pair<std::string, void (Harl::*)(void)>("WARNING", &Harl::_warning));
	_levels.insert(std::pair<std::string, void (Harl::*)(void)>("ERROR", &Harl::_error));
}

Harl::~Harl() {}

void	Harl::_debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::_info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::_warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::_error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	const char	*levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int count = 0;
	while (count < 4)
	{
		if (levels[count] == level)
			break;
		count++;
	}

	switch (count)
	{
		case 0:
			(this->*_levels["DEBUG"])();
			/* fall through */
		case 1:
			(this->*_levels["INFO"])();
			/* fall through */
		case 2:
			(this->*_levels["WARNING"])();
			/* fall through */
		case 3:
			(this->*_levels["ERROR"])();
			break;
		default:
			std::cout << "Invalid level" << std::endl;
			break;
	}
}
