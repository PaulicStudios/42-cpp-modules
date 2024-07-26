/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:00:33 by pgrossma          #+#    #+#             */
/*   Updated: 2024/07/26 17:24:44 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	_ideas = new std::string[100];
	std::cout << "Brain has been created" << std::endl;
}

Brain::Brain(Brain const &Brain) {
	*this = Brain;
	std::cout << "Brain has been copied" << std::endl;
}

Brain& Brain::operator=(Brain const &brain) {
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = brain._ideas[i];
	}
	std::cout << "Brain has been assigned" << std::endl;
	return (*this);
}

Brain::~Brain() {
	delete [] _ideas;
	std::cout << "Brain has been destroyed" << std::endl;
}
