#pragma once

#include "AForm.hpp"
class AForm;

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat {
private:
	const std::string _name;
	uint _grade;

public:
	Bureaucrat();
	Bureaucrat(std::string name, uint grade);
	Bureaucrat(Bureaucrat const &Bureaucrat);
	Bureaucrat &operator=(Bureaucrat const &Bureaucrat);
	~Bureaucrat();
	[[nodiscard]] std::string getName() const;
	[[nodiscard]] uint getGrade() const;
	void incrementGrade();
	void decrementGrade();

	void signAForm(AForm &AForm) const;

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
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);
