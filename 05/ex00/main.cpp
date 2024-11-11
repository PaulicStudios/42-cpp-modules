/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:49:21 by pgrossma          #+#    #+#             */
/*   Updated: 2024/09/05 17:29:34 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	Bureaucrat	bureaucrat("bureaucrat!", 150);
	std::cout << "Printing out << of bureaucrat" << std::endl;
	std::cout << bureaucrat << std::endl;

	std::cout << "Printing out the Name" << std::endl;
	std::cout << bureaucrat.getName() << std::endl;
	std::cout << "Printing out the grade" << std::endl;
	std::cout << bureaucrat.getGrade() << std::endl;

	std::cout << "Trying to create Bureaucrat with a grad of 151" << std::endl;
	try {
		Bureaucrat	bureaucrat151("bureaucrat", 151);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "Trying to create Bureaucrat with a grad of 0" << std::endl;
	try {
		Bureaucrat	bureaucrat0("bureaucrat", 0);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "Decrementing grade of first bureaucrat" << std::endl;
	try {
		bureaucrat.decrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "Incrementing grade of first bureaucrat" << std::endl;
	try {
		bureaucrat.incrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << bureaucrat << std::endl;

	std::cout << "Decrementing grade of first bureaucrat" << std::endl;
	try {
		bureaucrat.decrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << bureaucrat << std::endl;

	std::cout << "Created new Bureaucrat2" << std::endl;
	Bureaucrat	bureaucrat2("bureaucrat2", 2);
	std::cout << bureaucrat2 << std::endl;
	try {
		bureaucrat2.decrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << bureaucrat2 << std::endl;
	return (0);
}
