/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:49:21 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/19 18:15:37 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	{
		std::cout << "Form exceptions:" << std::endl;
		try {
			Form form("Form1", 0, 1);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			Form form("Form1", 1, 0);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			Form form("Form2", 151, 1);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			Form form("Form2", 1, 151);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "Form tests:" << std::endl;
		Form form("Form", 1, 1);
		std::cout << form << std::endl;

		Bureaucrat bureaucrat("John", 2);
		try {
			bureaucrat.signForm(form);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << form << std::endl;

		std::cout << "Incrementing bureaucrat grade..." << std::endl;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
		try {
			bureaucrat.signForm(form);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << form << std::endl;
		bureaucrat.signForm(form);
	}

	return (0);
}
