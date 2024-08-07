/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:34:44 by pgrossma          #+#    #+#             */
/*   Updated: 2024/07/29 10:45:33 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	_type = "Dog";
	std::cout << _type << " has been created" << std::endl;
}

Dog::Dog(Dog const &Dog) : Animal(Dog) {
	*this = Dog;
	std::cout << _type << " has been copied" << std::endl;
}

Dog& Dog::operator=(Dog const &Dog) {
	this->_type = Dog._type;
	std::cout << _type << " has been assigned" << std::endl;
	return (*this);
}

Dog::~Dog() {
	std::cout << _type << " has been destroyed" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Wouf wouf wowowof wowowowo fff" << std::endl;
}
