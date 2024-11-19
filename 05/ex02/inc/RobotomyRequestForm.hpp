/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:30:09 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/19 19:36:44 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    private:
        std::string _target;

        RobotomyRequestForm();
    public:
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const &RobotomyRequestForm);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &RobotomyRequestForm);
        ~RobotomyRequestForm();

        void execute(Bureaucrat const &executor) const;
};
