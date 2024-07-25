/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:46:42 by pgrossma          #+#    #+#             */
/*   Updated: 2024/07/25 17:55:29 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) {
	this->_name = "default";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "ClapTrap " << this->_name << " has been created" << std::endl;
}

ClapTrap::ClapTrap(std::string name) {
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "ClapTrap " << this->_name << " has been created" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &clapTrap) {
	*this = clapTrap;
	std::cout << "ClapTrap " << this->_name << " has been copied and created" << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap const &clapTrap) {
	this->_name = clapTrap._name;
	this->_hitPoints = clapTrap._hitPoints;
	this->_energyPoints = clapTrap._energyPoints;
	this->_attackDamage = clapTrap._attackDamage;
	std::cout << "ClapTrap " << this->_name << " has been assigned" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap " << this->_name << " has been destroyed" << std::endl;
}

void ClapTrap::attack(std::string const &target) {
	std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage!" << std::endl;
	--_energyPoints;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
	_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "ClapTrap " << this->_name << " is being repaired by " << amount << " points!" << std::endl;
	_hitPoints += amount;
	--_energyPoints;
}
