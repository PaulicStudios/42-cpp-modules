/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                       :+:      :+:    :+:   */
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

class WrongAnimal {
	protected:
		std::string	_type;
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const &WrongAnimal);
		WrongAnimal& operator=(WrongAnimal const &WrongAnimal);
		~WrongAnimal();

		std::string	getType() const;
		void		makeSound() const;
};
