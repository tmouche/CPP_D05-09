/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 04:12:22 by thibaud           #+#    #+#             */
/*   Updated: 2024/09/11 05:25:46 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.class.hpp"
#include "Bureaucrat.class.hpp"
#include <ctime>

RobotomyRequestFarm::RobotomyRequestFarm( void ) {
	return ;
}

RobotomyRequestFarm::~RobotomyRequestFarm( void ) {
	return ;
}

RobotomyRequestFarm::RobotomyRequestFarm(std::string target) : AForm("RobotomyRequestForm", 72, 45) {
	this->_target = target;
	return ;
}

RobotomyRequestFarm::RobotomyRequestFarm(RobotomyRequestFarm const & src) {
	*this = src;
	return ;
}

RobotomyRequestFarm& RobotomyRequestFarm::operator=(RobotomyRequestFarm const & rhs) {
	if (this != &rhs)
		this->_target = rhs._target;
	return *this;
}

void	RobotomyRequestFarm::execute(Bureaucrat const & executor) const {
	std::time_t	time = std::time({});
	char		str[1];

	try {
		if (executor.getGrade() > this->getGradeSign()
			|| executor.getGrade() > this->getGradeExecute())
			throw AForm::GradeTooLowException();
		else if (this->getSigned() == false)
			throw AForm::FormNotSigned();
		else {
			std::strftime(str, 1, "[%S]", std::gmtime(&time));
			if (*str / 2 % 2 == 0)
				std::cout << this->_target << " has been successfully robotomized!" << std::endl;
			else
				std::cout << this->_target << " robotomized failed!" << std::endl;
		}
	}
	catch (AForm::GradeTooLowException& e) {
		std::cout << executor.getName() << " couldn't execute " << this->getName() << " because his grade is too low!";
	}
	catch (AForm::FormNotSigned& e) {
		std::cout << executor.getName() << " have to sign " << this->getName() << " before execute it!";
	}
	return ;
}