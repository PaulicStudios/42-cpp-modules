/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:13:40 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/19 19:22:27 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

#include <fstream>

class ShrubberyCreationForm : public AForm {
    private:
        std::string _target;

        ShrubberyCreationForm();

    public:
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm const &ShrubberyCreationForm);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &ShrubberyCreationForm);
        ~ShrubberyCreationForm();

        void execute(Bureaucrat const &executor) const;
};