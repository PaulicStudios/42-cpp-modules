/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:34:44 by pgrossma          #+#    #+#             */
/*   Updated: 2024/07/29 15:51:59 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat: " << _type << " has been created" << std::endl;
}

Cat::Cat(Cat const &cat) : Animal(cat) {
	*this = cat;
	std::cout << "Cat: " << _type << " has been copied" << std::endl;
}

Cat& Cat::operator=(Cat const &cat) {
	this->_type = cat._type;
	_brain = new Brain(*cat._brain);

	std::cout << "Cat: " << cat._type << " has been assigned" << std::endl;
	return (*this);
}

Cat::~Cat() {
	delete _brain;
	std::cout << "Cat: " << _type << " has been destroyed" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Cat: " << "Miaaaooouuuooouuuu" << std::endl;
}

Brain	&Cat::getBrain() const {
	return (*_brain);
}
