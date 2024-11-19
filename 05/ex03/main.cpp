/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:49:21 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/19 21:57:22 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

#include <iostream>

int main()
{
	{
		Intern intern;
		AForm *form = intern.makeForm("shrubbery creation", "home");
		std::cout << *form << std::endl;
		delete form;
	}
	{
		Intern intern;
		AForm *form = intern.makeForm("robotomy request", "Bender");
		std::cout << *form << std::endl;
		delete form;
	}
	{
		Intern intern;
		AForm *form = intern.makeForm("presidential pardon", "Bender");
		std::cout << *form << std::endl;
		delete form;
	}
	{
		Intern intern;
		AForm *form = intern.makeForm("unknown form", "Bender");
		if (form)
		{
			std::cout << *form << std::endl;
			delete form;
		}
	}

	return (0);
}
