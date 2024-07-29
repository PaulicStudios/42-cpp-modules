/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:00:33 by pgrossma          #+#    #+#             */
/*   Updated: 2024/07/29 11:35:19 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
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
	std::cout << "Brain has been destroyed" << std::endl;
}

std::string Brain::getIdea(int index) const {
	if (index < 0 || index >= 100) {
		return ("");
	}
	return (_ideas[index]);
}

void Brain::setIdea(int index, std::string idea) {
	if (index < 0 || index >= 100) {
		return ;
	}
	_ideas[index] = idea;
}
