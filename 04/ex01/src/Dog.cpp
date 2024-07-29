/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:34:44 by pgrossma          #+#    #+#             */
/*   Updated: 2024/07/29 12:03:22 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	_type = "Dog";
	std::cout << "Dog: " << _type << " has been created" << std::endl;
}

Dog::Dog(Dog const &Dog) : Animal(Dog) {
	*this = Dog;
	std::cout << "Dog: " << _type << " has been copied" << std::endl;
}

Dog& Dog::operator=(Dog const &dog) {
	std::cout << "Dog: " << dog._type << " has been assigned" << std::endl;
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog: " << _type << " has been destroyed" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Dog: " << "Wouf wouf wowowof wowowowo fff" << std::endl;
}
