/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:22:07 by thibaud           #+#    #+#             */
/*   Updated: 2024/09/11 04:34:52 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.class.hpp"
#include "Bureaucrat.class.hpp"

AForm::AForm( void ) : _name(0), _gradeSign(1) ,_gradeExecute(1) {
	this->_signed = false;
	return ;
}

AForm::~AForm( void ) {
	return ;
}

AForm::AForm(std::string name, int gSign, int gExec) : _name(name), _gradeSign(gSign), _gradeExecute(gExec) {
	this->_signed = false;
	return ;
}

AForm::AForm(AForm const & src)  : _name(src._name), _gradeSign(src._gradeSign), _gradeExecute(_gradeExecute) {
	*this = src;
	return ;
}

AForm&	AForm::operator=(AForm const & rhs) {
	if (this != &rhs) {
		this->_signed = rhs._signed;
	}
	return *this;
}

std::string	AForm::getName( void ) const {
	return this->_name;	
}

bool	AForm::getSigned( void ) const {
	return this->_signed;
}

int	AForm::getGradeSign( void ) const {
	return this->_gradeSign;
}

int	AForm::getGradeExecute( void ) const {
	return this->_gradeExecute;
}

void	AForm::beSigned(Bureaucrat const & src) {
	if (src.getGrade() > this->_gradeSign)
		throw AForm::GradeTooLowException();
	this->_signed = true;
	std::cout << src.getName() << " signed " << this->_name << std::endl;
	return ;
}

std::ostream& operator<<(std::ostream& o, AForm const &rhs) {
	o << rhs.getName();
	if (rhs.getSigned())
		o << ", is signed";
	else
		o << ", is not signed";
	o << ", have to be at the grade " << rhs.getGradeSign() << " to sign!";
	o << ", have to be at the grade " << rhs.getGradeExecute() << " to execute!" << std::endl;
	return o;
}