/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:10:38 by pgrossma          #+#    #+#             */
/*   Updated: 2024/07/29 12:01:40 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	// const Animal* j = new Dog();
	const Cat* i = new Cat();
	// std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!

	Cat *j = new Cat(*i);

	i->getBrain()->setIdea(0, "Idea 1");

	std::cout << j->getType() << ": " << j->getBrain()->getIdea(0) << std::endl;

	// j->makeSound();

	// const Animal* meta = new Animal();
	// meta->makeSound();
	// delete meta;

	delete j;
	delete i;
}
