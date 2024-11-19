/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:36:12 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/19 21:46:18 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() = default;

Intern::Intern(Intern const &Intern) = default;

Intern &Intern::operator=(Intern const &Intern) = default;

Intern::~Intern() = default;

AForm *Intern::makeForm(std::string formName, std::string target) {
    struct FormType {
        std::string name;
        AForm* (*create)(std::string);
    };
    static FormType forms[] = {
        {"shrubbery creation", [](std::string target) -> AForm* { return new ShrubberyCreationForm(target); }},
        {"robotomy request", [](std::string target) -> AForm* { return new RobotomyRequestForm(target); }},
        {"presidential pardon", [](std::string target) -> AForm* { return new PresidentialPardonForm(target); }}
    };

    for (int i = 0; i < 3; i++) {
        if (forms[i].name == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (forms[i].create(target));
        }
    }

    std::cout << "Intern cannot create " << formName << std::endl;
    return (nullptr);
}
