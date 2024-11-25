/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche < tmouche@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 03:56:19 by thibaud           #+#    #+#             */
/*   Updated: 2024/11/22 15:11:49 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.class.hpp"
#include "Bureaucrat.class.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm( void ) {
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137) {
	this->_target = target;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src.getName(), src.getGradeSign(), src.getGradeExecute()) {
	*this = src;
	return ;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs) {
	if (this != &rhs) {
		this->_target = rhs._target;
	}
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
  if (executor.getGrade() > this->getGradeSign()
  	|| executor.getGrade() > this->getGradeExecute())
  	throw AForm::GradeTooLowException();
  else if (this->getSigned() == false)
  	throw AForm::FormNotSigned();
  std::ofstream	ofs((this->_target + "_shrubbery").c_str());
  ofs << "TREE IN ASCII";
  ofs.close();
  std::cout << executor.getName() << " executed " << this->getName() << std::endl;
  return ;
}
