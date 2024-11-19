/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:35:41 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/19 21:52:05 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <string>

class Intern {
    public:
        Intern();
        Intern(Intern const &Intern);
        Intern &operator=(Intern const &Intern);
        ~Intern();

        AForm *makeForm(std::string formName, std::string target);
};
