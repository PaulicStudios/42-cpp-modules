/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:41:09 by pgrossma          #+#    #+#             */
/*   Updated: 2024/07/25 19:23:08 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	_name = "default";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " has been created" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " has been created" << std::endl;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src)
{
	*this = src;
	std::cout << "FragTrap " << _name << " has been copied and created" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &FragTrap)
{
	_name = FragTrap._name;
	_hitPoints = FragTrap._hitPoints;
	_energyPoints = FragTrap._energyPoints;
	_attackDamage = FragTrap._attackDamage;
	std::cout << "FragTrap " << _name << " has been assigned" << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " has been destroyed" << std::endl;
}

void FragTrap::highFiveGuys()
{
	std::cout << "FragTrap " << _name << " says: High five, guys!" << std::endl;
}
