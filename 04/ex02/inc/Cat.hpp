/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:34:05 by pgrossma          #+#    #+#             */
/*   Updated: 2024/07/29 15:32:12 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat: public Animal {
	private:
		Brain	*_brain;
	public:
		Cat();
		Cat(Cat const &Cat);
		Cat& operator=(Cat const &Cat);
		~Cat();

		void	makeSound() const;
		Brain	&getBrain() const;
};
