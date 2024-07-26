/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:46:42 by pgrossma          #+#    #+#             */
/*   Updated: 2024/07/25 17:55:29 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	_type = "WrongAnimal";
	std::cout << _type << " has been created" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &WrongAnimal) {
	*this = WrongAnimal;
	std::cout << _type << " has been copied" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const &WrongAnimal) {
	this->_type = WrongAnimal._type;
	std::cout << _type << " has been assigned" << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << _type << " has been destroyed" << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType() const {
	return (_type);
}
