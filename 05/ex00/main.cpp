/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:49:21 by pgrossma          #+#    #+#             */
/*   Updated: 2024/09/05 16:31:03 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	Bureaucrat	bureaucrat("bureaucrat", 150);

	std::cout << bureaucrat.getName() << std::endl;
	std::cout << bureaucrat.getGrade() << std::endl;
	try {
		Bureaucrat	bureaucrat("bureaucrat", 0);
	} catch (std::exception &e) {
		std::cout << "Grade too high" << e.what() << std::endl;
	}
	bureaucrat.incrementGrade();
	std::cout << bureaucrat.getGrade() << std::endl;
	bureaucrat.decrementGrade();
	std::cout << bureaucrat.getGrade() << std::endl;
	return (0);
}
