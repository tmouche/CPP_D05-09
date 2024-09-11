/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 04:12:22 by thibaud           #+#    #+#             */
/*   Updated: 2024/09/11 18:39:23 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.class.hpp"
#include "Bureaucrat.class.hpp"
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm( void ) {
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45) {
	this->_target = target;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) {
	*this = src;
	return ;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs) {
	if (this != &rhs)
		this->_target = rhs._target;
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	std::time_t	time = std::time({});
	char		str[4];

	if (executor.getGrade() > this->getGradeSign()
		|| executor.getGrade() > this->getGradeExecute())
		throw AForm::GradeTooLowException();
	else if (this->getSigned() == false)
		throw AForm::FormNotSigned();
	std::strftime(str, 4, "[%S]", std::gmtime(&time));
	if (str[1] / 2 % 2 == 0)
		std::cout << this->_target << " has been successfully robotomized!" << std::endl;
	else
		std::cout << this->_target << " robotomized failed!" << std::endl;
  	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
	return ;
}