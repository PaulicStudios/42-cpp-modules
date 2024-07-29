/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:10:38 by pgrossma          #+#    #+#             */
/*   Updated: 2024/07/29 16:21:55 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Cat* i = new Cat();
	// const Cat* i = new Animal();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();

	Cat *j = new Cat(*i);

	i->getBrain().setIdea(0, "Idea 1");

	std::cout << j->getType() << ": " << j->getBrain().getIdea(0) << std::endl;

	delete j;
	delete i;
}
