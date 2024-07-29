/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:34:05 by pgrossma          #+#    #+#             */
/*   Updated: 2024/07/29 11:26:52 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat: public Animal {
	public:
		Cat();
		Cat(Cat const &Cat);
		Cat& operator=(Cat const &Cat);
		~Cat();

		void	makeSound() const;
};
