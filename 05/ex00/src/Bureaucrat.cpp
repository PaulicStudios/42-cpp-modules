/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:22:14 by pgrossma          #+#    #+#             */
/*   Updated: 2024/09/05 16:45:32 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string name, uint grade) : _name(name) {
	if (grade < 1) {
		throw GradeTooHighException();
	} else if (grade > 150) {
		throw GradeTooLowException();
	}
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &Bureaucrat) : _name(Bureaucrat._name) {
	this->_grade = Bureaucrat._grade;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &Bureaucrat) {
	this->_grade = Bureaucrat._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() = default;

std::string Bureaucrat::getName() const {
	return (this->_name);
}

uint Bureaucrat::getGrade() const {
	return (this->_grade);
}

void Bureaucrat::incrementGrade() {
	if (this->_grade <= 1) {
		throw GradeTooHighException();
	}
	this->_grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->_grade >= 150) {
		throw GradeTooLowException();
	}
	this->_grade++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}
