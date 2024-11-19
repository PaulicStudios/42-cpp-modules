/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:44:19 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/19 19:44:53 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    private:
        PresidentialPardonForm();
    public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm const &PresidentialPardonForm);
        PresidentialPardonForm &operator=(PresidentialPardonForm const &);
        ~PresidentialPardonForm();

        void execute(Bureaucrat const &executor) const;
};
