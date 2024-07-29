/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:34:05 by pgrossma          #+#    #+#             */
/*   Updated: 2024/07/29 15:32:16 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog: public Animal {
	private:
		Brain	*_brain;
	public:
		Dog();
		Dog(Dog const &Dog);
		Dog& operator=(Dog const &Dog);
		~Dog();

		void	makeSound() const;
		Brain	&getBrain() const;
};
