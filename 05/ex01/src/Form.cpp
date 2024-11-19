/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:26:01 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/19 15:39:42 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(1), _gradeToExecute(1) {}

Form::Form(std::string name, uint gradeToSign, uint gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw GradeTooHighException();
    } else if (gradeToSign > 150 || gradeToExecute > 150) {
        throw GradeTooLowException();
    }
}

Form::Form(Form const &Form) : _name(Form._name), _signed(Form._signed), _gradeToSign(Form._gradeToSign), _gradeToExecute(Form._gradeToExecute) {}

Form &Form::operator=(Form const &Form) {
    this->_signed = Form._signed;
    return (*this);
}

Form::~Form() = default;

std::string Form::getName() const {
    return (this->_name);
}

bool Form::getSigned() const {
    return (this->_signed);
}

uint Form::getGradeToSign() const {
    return (this->_gradeToSign);
}

uint Form::getGradeToExecute() const {
    return (this->_gradeToExecute);
}

void Form::beSigned(Bureaucrat const &bureaucrat) {
    if (bureaucrat.getGrade() > this->_gradeToSign) {
        throw GradeTooLowException();
    }
    if (this->_signed) {
        std::cout << "Info: Form already signed" << std::endl;
        return;
    }

    this->_signed = true;
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
    out << "Form " << form.getName() << " is " << (form.getSigned() ? "signed" : "not signed") << " and requires grade " << form.getGradeToSign() << " to sign and grade " << form.getGradeToExecute() << " to execute";
    return (out);
}