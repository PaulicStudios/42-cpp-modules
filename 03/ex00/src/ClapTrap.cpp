/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:46:42 by pgrossma          #+#    #+#             */
/*   Updated: 2024/07/25 17:35:45 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) {
	this->_name = "default";
	this->_hitpoints = 10;
	this->_energy_points = 10;
	this->_attack_damage = 0;
	std::cout << "ClapTrap " << this->_name << " has been created" << std::endl;
}

ClapTrap::ClapTrap(std::string name) {
	this->_name = name;
	this->_hitpoints = 10;
	this->_energy_points = 10;
	this->_attack_damage = 0;
	std::cout << "ClapTrap " << this->_name << " has been created" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &clapTrap) {
	*this = clapTrap;
	std::cout << "ClapTrap " << this->_name << " has been copied and created" << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap const &clapTrap) {
	this->_name = clapTrap._name;
	this->_hitpoints = clapTrap._hitpoints;
	this->_energy_points = clapTrap._energy_points;
	this->_attack_damage = clapTrap._attack_damage;
	std::cout << "ClapTrap " << this->_name << " has been assigned" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap " << this->_name << " has been destroyed" << std::endl;
}

void ClapTrap::attack(std::string const &target) {
	std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_attack_damage << " points of damage!" << std::endl;
	--_energy_points;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
	_hitpoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "ClapTrap " << this->_name << " is being repaired by " << amount << " points!" << std::endl;
	_hitpoints += amount;
	--_energy_points;
}
