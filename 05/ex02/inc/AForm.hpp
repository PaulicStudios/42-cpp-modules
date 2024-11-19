/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:26:08 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/19 15:54:30 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
class Bureaucrat;

#include <string>
#include <exception>
#include <iostream>

class AForm {
private:
    const std::string _name;
    bool _signed;
    const uint _gradeToSign;
    const uint _gradeToExecute;
    AForm();

public:
    AForm(std::string name, uint gradeToSign, uint gradeToExecute);
    AForm(AForm const &AForm);
    AForm &operator=(AForm const &AForm);
    ~AForm();

    std::string getName() const;
    bool getSigned() const;
    uint getGradeToSign() const;
    uint getGradeToExecute() const;

    void beSigned(Bureaucrat const &bureaucrat);
    virtual void execute(Bureaucrat const &executor) const = 0;

    class GradeTooHighException final : public std::exception {
        public:
            [[nodiscard]] const char *what() const noexcept override {
                return ("Grade too high");
            }
    };
    class GradeTooLowException final : public std::exception {
        public:
            [[nodiscard]] const char *what() const noexcept override {
                return ("Grade too low");
            }
    };
    class FormNotSignedException final : public std::exception {
        public:
            [[nodiscard]] const char *what() const noexcept override {
                return ("Form not signed");
            }
    };
};

std::ostream &operator<<(std::ostream &out, const AForm &AForm);