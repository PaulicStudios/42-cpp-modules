/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:26:01 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/19 15:53:47 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(1), _gradeToExecute(1), _target("default") {}

AForm::AForm(std::string name, uint gradeToSign, uint gradeToExecute, std::string target) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _target(target) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw GradeTooHighException();
    } else if (gradeToSign > 150 || gradeToExecute > 150) {
        throw GradeTooLowException();
    }
}

AForm::AForm(AForm const &AForm) : _name(AForm._name), _signed(AForm._signed), _gradeToSign(AForm._gradeToSign), _gradeToExecute(AForm._gradeToExecute), _target(AForm._target) {}

AForm::~AForm() = default;

AForm &AForm::operator=(AForm const &AForm) {
    this->_signed = AForm._signed;
    return (*this);
}

std::string AForm::getName() const {
    return (this->_name);
}

bool AForm::getSigned() const {
    return (this->_signed);
}

uint AForm::getGradeToSign() const {
    return (this->_gradeToSign);
}

uint AForm::getGradeToExecute() const {
    return (this->_gradeToExecute);
}

std::string AForm::getTarget() const {
    return (this->_target);
}

void AForm::beSigned(Bureaucrat const &bureaucrat) {
    if (bureaucrat.getGrade() > this->_gradeToSign) {
        throw GradeTooLowException();
    }
    if (this->_signed) {
        std::cout << "Info: Form already signed" << std::endl;
        return;
    }

    this->_signed = true;
}

void AForm::checkExecution(Bureaucrat const &executor) const {
    if (!this->_signed)
        throw FormNotSignedException();
    if (executor.getGrade() > this->_gradeToExecute)
        throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const AForm &AForm) {
    out << "Form " << AForm.getName() << " is " << (AForm.getSigned() ? "signed" : "not signed") << " and requires grade " << AForm.getGradeToSign() << " to sign and grade " << AForm.getGradeToExecute() << " to execute";
    return (out);
}