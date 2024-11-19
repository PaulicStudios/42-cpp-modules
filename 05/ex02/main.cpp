/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:49:21 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/19 16:06:00 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

int main()
{
	{
		std::cout << "AForm exceptions:" << std::endl;
		try {
			AForm AForm("AForm1", 0);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			AForm AForm("AForm2", 151);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "AForm tests:" << std::endl;
		AForm AForm("AForm", 1);
		std::cout << AForm << std::endl;

		Bureaucrat bureaucrat("John", 2);
		try {
			bureaucrat.signAForm(AForm);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << AForm << std::endl;

		std::cout << "Incrementing bureaucrat grade..." << std::endl;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
		try {
			bureaucrat.signAForm(AForm);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << AForm << std::endl;
		bureaucrat.signAForm(AForm);
	}

	return (0);
}
