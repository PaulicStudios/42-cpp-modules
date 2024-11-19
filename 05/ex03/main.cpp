/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:49:21 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/19 21:26:54 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

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
		std::cout << "PresidentialPardonForm tests:" << std::endl;
		PresidentialPardonForm presidentialPardonForm("home");
		std::cout << presidentialPardonForm << std::endl;

		Bureaucrat bureaucrat("Bureaucrat", 26);
		try {
			std::cout << "Signing form" << std::endl;
			bureaucrat.signForm(presidentialPardonForm);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			std::cout << "Executing form" << std::endl;
			bureaucrat.executeForm(presidentialPardonForm);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << presidentialPardonForm << std::endl;

		std::cout << std::endl;

		Bureaucrat bureaucrat2("Bureaucrat2", 6);
		std::cout << "signing form" << std::endl;
		bureaucrat2.signForm(presidentialPardonForm);

		std::cout << "trying to execute form" << std::endl;
		try {
			bureaucrat2.executeForm(presidentialPardonForm);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << presidentialPardonForm << std::endl;

		std::cout << std::endl;

		Bureaucrat bureaucrat3("Bureaucrat3", 1);
		std::cout << "signing form" << std::endl;
		bureaucrat3.signForm(presidentialPardonForm);
		std::cout << "executing form" << std::endl;
		bureaucrat3.executeForm(presidentialPardonForm);
		std::cout << presidentialPardonForm << std::endl;
	}
	std::cout << "----------------------------------------" << std::endl;
	{
		std::cout << "RobotomyRequestForm tests:" << std::endl;
		RobotomyRequestForm robotomyRequestForm("home");
		std::cout << robotomyRequestForm << std::endl;

		Bureaucrat bureaucrat("Bureaucrat", 73);
		try {
			std::cout << "Signing form" << std::endl;
			bureaucrat.signForm(robotomyRequestForm);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			std::cout << "Executing form" << std::endl;
			bureaucrat.executeForm(robotomyRequestForm);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << robotomyRequestForm << std::endl;

		std::cout << std::endl;

		Bureaucrat bureaucrat2("Bureaucrat2", 46);
		std::cout << "signing form" << std::endl;
		bureaucrat2.signForm(robotomyRequestForm);

		std::cout << "trying to execute form" << std::endl;
		try {
			bureaucrat2.executeForm(robotomyRequestForm);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << robotomyRequestForm << std::endl;

		std::cout << std::endl;

		Bureaucrat bureaucrat3("Bureaucrat3", 1);
		std::cout << "signing form" << std::endl;
		bureaucrat3.signForm(robotomyRequestForm);
		std::cout << "executing form" << std::endl;
		bureaucrat3.executeForm(robotomyRequestForm);
		bureaucrat3.executeForm(robotomyRequestForm);
		bureaucrat3.executeForm(robotomyRequestForm);
		bureaucrat3.executeForm(robotomyRequestForm);
		bureaucrat3.executeForm(robotomyRequestForm);
		bureaucrat3.executeForm(robotomyRequestForm);
		bureaucrat3.executeForm(robotomyRequestForm);
		bureaucrat3.executeForm(robotomyRequestForm);

		bureaucrat3.executeForm(robotomyRequestForm);
		std::cout << robotomyRequestForm << std::endl;
	}

	return (0);
}
