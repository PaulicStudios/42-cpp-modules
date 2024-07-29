/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:34:44 by pgrossma          #+#    #+#             */
/*   Updated: 2024/07/29 11:30:35 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	_type = "Cat";
	std::cout << _type << " has been created" << std::endl;
}

Cat::Cat(Cat const &Cat) : Animal(Cat) {
	*this = Cat;
	std::cout << _type << " has been copied" << std::endl;
}

Cat& Cat::operator=(Cat const &Cat) {
	this->_type = Cat._type;
	this->_brain = Cat._brain;

	std::cout << _type << " has been assigned" << std::endl;
	return (*this);
}

Cat::~Cat() {
	std::cout << _type << " has been destroyed" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Miaaaooouuuooouuuu" << std::endl;
}
