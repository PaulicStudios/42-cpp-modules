#pragma once

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat {
	private:
		const std::string	_name;
		uint				_grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, uint grade);
		Bureaucrat(Bureaucrat const &Bureaucrat);
		Bureaucrat &operator=(Bureaucrat const &Bureaucrat);
		~Bureaucrat();

		std::string	getName() const;
		uint		getGrade() const;
		void		incrementGrade();
		void		decrementGrade();

	class GradeTooHighException : public std::exception {
		public:
			virtual const char *what() const throw() {
				return ("Grade too high");
			}
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char *what() const throw() {
				return ("Grade too low");
			}
	};
};

std::ostream &operator<<(std::ostream &out, Bureaucrat &bureaucrat);
