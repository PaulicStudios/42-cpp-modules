/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:44:53 by pgrossma          #+#    #+#             */
/*   Updated: 2024/07/25 17:55:29 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Brain.hpp"

class Animal {
	protected:
		std::string	_type;
		Brain		*_brain;
	public:
		Animal();
		Animal(Animal const &Animal);
		Animal& operator=(Animal const &Animal);
		virtual ~Animal();

		std::string		getType() const;
		virtual void	makeSound() const = 0;
};
