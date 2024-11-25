/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche < tmouche@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 04:21:51 by thibaud           #+#    #+#             */
/*   Updated: 2024/11/22 15:09:35 by tmouche          ###   ########.fr       */
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

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : AForm(src.getName(), src.getGradeSign(), src.getGradeExecute()) {
	*this = src;
	return ;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs) {
	if (this != &rhs)
		this->_target = rhs._target;
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > this->getGradeSign()
		|| executor.getGrade() > this->getGradeExecute())
		throw AForm::GradeTooLowException();
	else if (this->getSigned() == false)
		throw AForm::FormNotSigned();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
  	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
	return ;
}
