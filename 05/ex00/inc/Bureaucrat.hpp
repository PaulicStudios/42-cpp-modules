/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:26:38 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/19 15:26:39 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat {
private:
	const std::string _name;
	uint _grade;

public:
	Bureaucrat();
	Bureaucrat(std::string name, uint grade);
	Bureaucrat(Bureaucrat const &Bureaucrat);
	Bureaucrat &operator=(Bureaucrat const &Bureaucrat);
	~Bureaucrat();
	[[nodiscard]] std::string getName() const;
	[[nodiscard]] uint getGrade() const;
	void incrementGrade();
	void decrementGrade();

	class GradeTooHighException final : public std::exception {
	public:
		[[nodiscard]] const char *what() const noexcept override {
			return ("Grade too high");
		}
	};

	class GradeTooLowException final : public std::exception {
	public:
		[[nodiscard]] const char *what() const noexcept override {
			return ("Grade too low");
		}
	};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);
