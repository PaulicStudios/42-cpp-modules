/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:49:21 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/19 19:29:40 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main()
{
	{
		std::cout << "ShrubberyCreationForm tests:" << std::endl;
		ShrubberyCreationForm shrubberyCreationForm("home");
		std::cout << shrubberyCreationForm << std::endl;

		Bureaucrat bureaucrat("Bureaucrat", 146);
		try {
			std::cout << "Signing form" << std::endl;
			bureaucrat.signForm(shrubberyCreationForm);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			std::cout << "Executing form" << std::endl;
			bureaucrat.executeForm(shrubberyCreationForm);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << shrubberyCreationForm << std::endl;

		std::cout << std::endl;

		Bureaucrat bureaucrat2("Bureaucrat2", 138);
		std::cout << "signing form" << std::endl;
		bureaucrat2.signForm(shrubberyCreationForm);

		std::cout << "trying to execute form" << std::endl;
		try {
			bureaucrat2.executeForm(shrubberyCreationForm);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << shrubberyCreationForm << std::endl;

		std::cout << std::endl;

		Bureaucrat bureaucrat3("Bureaucrat3", 1);
		std::cout << "signing form" << std::endl;
		bureaucrat3.signForm(shrubberyCreationForm);
		std::cout << "executing form" << std::endl;
		bureaucrat3.executeForm(shrubberyCreationForm);
		std::cout << shrubberyCreationForm << std::endl;
	}
	std::cout << "----------------------------------------" << std::endl;
	{
		
	}

	return (0);
}