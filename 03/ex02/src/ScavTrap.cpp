/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:41:09 by pgrossma          #+#    #+#             */
/*   Updated: 2024/07/25 19:17:32 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	_name = "default";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_guardGate = false;
	std::cout << "ScavTrap " << _name << " has been created" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_guardGate = false;
	std::cout << "ScavTrap " << _name << " has been created" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src)
{
	*this = src;
	std::cout << "ScavTrap " << _name << " has been copied and created" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &scavTrap)
{
	_name = scavTrap._name;
	_hitPoints = scavTrap._hitPoints;
	_energyPoints = scavTrap._energyPoints;
	_attackDamage = scavTrap._attackDamage;
	_guardGate = scavTrap._guardGate;
	std::cout << "ScavTrap " << _name << " has been assigned" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " has been destroyed" << std::endl;
}

void ScavTrap::attack(std::string const &target)
{
	std::cout << "ScavTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
	--_energyPoints;
}

void ScavTrap::guardGate()
{
	_guardGate = !_guardGate;
	if (_guardGate)
		std::cout << "ScavTrap " << _name << " has entered gate keeper mode" << std::endl;
	else
		std::cout << "ScavTrap " << _name << " has exited gate keeper mode" << std::endl;
}
