/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:30:53 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/19 19:43:34 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45, "default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &RobotomyRequestForm) : AForm(RobotomyRequestForm) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &) {
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() = default;

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (!this->getSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::cout << "DRILLING NOISES" << std::endl;
    std::cout << "*drilling noises*" << std::endl;

    if (rand() % 2)
        std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
    else
        std::cout << "Robotomy on " << this->getTarget() << " failed" << std::endl;
}
