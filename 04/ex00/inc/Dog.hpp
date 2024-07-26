/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:34:05 by pgrossma          #+#    #+#             */
/*   Updated: 2024/07/26 13:36:32 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

class Dog: public Animal {
	public:
		Dog();
		Dog(Dog const &Dog);
		Dog& operator=(Dog const &Dog);
		~Dog(void);
};
