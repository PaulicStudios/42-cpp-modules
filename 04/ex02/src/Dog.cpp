/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:34:44 by pgrossma          #+#    #+#             */
/*   Updated: 2024/07/29 15:35:48 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	_type = "Dog";
	_brain = new Brain();
	std::cout << "Dog: " << _type << " has been created" << std::endl;
}

Dog::Dog(Dog const &dog) : Animal(dog) {
	*this = dog;
	std::cout << "Dog: " << _type << " has been copied" << std::endl;
}

Dog& Dog::operator=(Dog const &dog) {
	this->_type = dog._type;
	_brain = new Brain(*dog._brain);

	std::cout << "Dog: " << dog._type << " has been assigned" << std::endl;
	return (*this);
}

Dog::~Dog() {
	delete _brain;
	std::cout << "Dog: " << _type << " has been destroyed" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Dog: " << "Wouf wouf wowowof wowowowo fff" << std::endl;
}

Brain	&Dog::getBrain() const {
	return (*_brain);
}
