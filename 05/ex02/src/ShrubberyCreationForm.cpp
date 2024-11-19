/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrossma <pgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:16:54 by pgrossma          #+#    #+#             */
/*   Updated: 2024/11/19 19:25:08 by pgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &ShrubberyCreationForm) : AForm(ShrubberyCreationForm), _target(ShrubberyCreationForm._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &ShrubberyCreationForm) {
    this->_target = ShrubberyCreationForm._target;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() = default;

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (this->getSigned() == false) {
        throw AForm::FormNotSignedException();
    }

    if (executor.getGrade() > this->getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }

    std::ofstream file(this->_target + "_shrubbery");
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file");
    }

    std::string tree = R"(
* Season's Greetings * 11/96
      __,_,_,___)          _______
    (--| | |             (--/    ),_)        ,_)
       | | |  _ ,_,_        |     |_ ,_ ' , _|_,_,_, _  ,
     __| | | (/_| | (_|     |     | ||  |/_)_| | | |(_|/_)___,
    (      |___,   ,__|     \____)  |__,           |__,

                            |                         _...._
                         \  _  /                    .::o:::::.
                          (\o/)                    .:::'''':o:.
                      ---  / \  ---                :o:_    _:::
                           >*<                     `:}_>()<_{:'
                          >0<@<                 @    `'//\\'`    @
                         >>>@<<*              @ #     //  \\     # @
                        >@>*<0<<<           __#_#____/'____'\____#_#__
                       >*>>@<<<@<<         [__________________________]
                      >@>>0<<<*<<@<         |=_- .-/\ /\ /\ /\--. =_-|
                     >*>>0<<@<<<@<<<        |-_= | \ \\ \\ \\ \ |-_=-|
                    >@>>*<<@<>*<<0<*<       |_=-=| / // // // / |_=-_|
      \*/          >0>>*<<@<>0><<*<@<<      |=_- |`-'`-'`-'`-'  |=_=-|
  ___\\U//___     >*>>@><0<<*>>@><*<0<<     | =_-| o          o |_==_|
  |\\ | | \\|    >@>>0<*<<0>>@<<0<<<*<@<    |=_- | !     (    ! |=-_=|
  | \\| | _(UU)_ >((*))_>0><*<0><@<<<0<*<  _|-,-=| !    ).    ! |-_-=|_
  |\ \| || / //||.*.*.*.|>>@<<*<<@>><0<<@</=-((=_| ! __(:')__ ! |=_==_-\
  |\\_|_|&&_// ||*.*.*.*|_\\db//__     (\_/)-=))-|/^\=^=^^=^=/^\| _=-_-_\
  """"|'.'.'.|~~|.*.*.*|     ____|_   =('.')=//   ,------------.
  jgs |'.'.'.|   ^^^^^^|____|>>>>>>|  ( ~~~ )/   (((((((())))))))
      ~~~~~~~~         '""""`------'  `w---w`     `------------'
    )";

    file << tree << std::endl;
    file.close();
}
