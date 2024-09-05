#pragma once

#include <string>
#include <exception>

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
		uint		getGrade();
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
