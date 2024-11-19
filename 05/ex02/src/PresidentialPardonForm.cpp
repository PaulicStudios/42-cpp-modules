/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:45:35 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/19 19:50:29 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5, "default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5, target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &PresidentialPardonForm) : AForm(PresidentialPardonForm) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &) {
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() = default;

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    checkExecution(executor);

    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
