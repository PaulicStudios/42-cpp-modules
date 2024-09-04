#pragma once

class Bureaucrat {
	private:
		const std::string	_name;
		uint				_grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, uint grade);
		Bureaucrat(Bureaucrat const &Bureaucrat);
		~Bureaucrat();

	class GradeTooHighException : public exception {}
	class GradeTooLowException : public exception {}
};
