/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 04:21:51 by thibaud           #+#    #+#             */
/*   Updated: 2024/09/11 04:43:47 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.class.hpp"
#include "Bureaucrat.class.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) {
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5) {
	this->_target = target;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) {
	*this = src;
	return ;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs) {
	if (this != &rhs)
		this->_target = rhs._target;
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	try {
		if (executor.getGrade() > this->getGradeSign()
			|| executor.getGrade() > this->getGradeExecute())
			throw AForm::GradeTooLowException();
		else if (this->getSigned() == false)
			throw AForm::FormNotSigned();
		else
			std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
	}
	catch (AForm::GradeTooLowException& e) {
		std::cout << executor.getName() << " couldn't execute " << this->getName() << " because his grade is too low!";
	}
	catch (AForm::FormNotSigned& e) {
		std::cout << executor.getName() << " have to sign " << this->getName() << " before execute it!";
	}
	return ;
}
