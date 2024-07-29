/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:46:42 by pgrossma          #+#    #+#             */
/*   Updated: 2024/07/25 17:55:29 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	_type = "Animal";
	_brain = new Brain();
	std::cout << _type << " has been created" << std::endl;
}

Animal::Animal(Animal const &Animal) {
	*this = Animal;
	std::cout << _type << " has been copied" << std::endl;
}

Animal& Animal::operator=(Animal const &Animal) {
	this->_type = Animal._type;
	_brain = Animal._brain;
	std::cout << _type << " has been assigned" << std::endl;
	return (*this);
}

Animal::~Animal() {
	delete _brain;
	std::cout << _type << " has been destroyed" << std::endl;
}

std::string Animal::getType() const {
	return (_type);
}
