/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:34:44 by pgrossma          #+#    #+#             */
/*   Updated: 2024/07/26 14:42:55 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
	_type = "WrongCat";
	std::cout << _type << " has been created" << std::endl;
}

WrongCat::WrongCat(WrongCat const &WrongCat) {
	*this = WrongCat;
	std::cout << _type << " has been copied" << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat const &WrongCat) {
	this->_type = WrongCat._type;
	std::cout << _type << " has been assigned" << std::endl;
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << _type << " has been destroyed" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "Miaaaooouuuooouuuu" << std::endl;
}
