/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:26:08 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/19 15:34:02 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <exception>
#include <iostream>

class Form {
    private:
        const std::string _name;
        bool _signed;
        const uint _gradeToSign;
        const uint _gradeToExecute;

        Form();
    
    public:
        Form(std::string name, uint gradeToSign, uint gradeToExecute);
        Form(Form const &Form);
        Form &operator=(Form const &Form);
        ~Form();

    class GradeTooHighException final : public std::exception {
        public:
            [[nodiscard]] const char *what() const noexcept override {
                return ("Grade too high");
            }
    }
    class GradeTooLowException final : public std::exception {
        public:
            [[nodiscard]] const char *what() const noexcept override {
                return ("Grade too low");
            }
    }
}

std::ostream &operator<<(std::ostream &out, const Form &form);