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
	Bureaucrat	bureaucrat("bureaucrat", 150);
	std::cout << bureaucrat << std::endl;
	std::cout << bureaucrat.getName() << std::endl;
	std::cout << bureaucrat.getGrade() << std::endl;

	try {
		Bureaucrat	bureaucrat151("bureaucrat", 151);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat	bureaucrat0("bureaucrat", 0);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		bureaucrat.decrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		bureaucrat.incrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << bureaucrat << std::endl;
	try {
		bureaucrat.decrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << bureaucrat << std::endl;

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
