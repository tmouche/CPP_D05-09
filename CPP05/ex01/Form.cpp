/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:22:07 by thibaud           #+#    #+#             */
/*   Updated: 2024/09/09 22:23:17 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.class.hpp"
#include "Bureaucrat.class.hpp"

Form::Form( void ) : _name(0), _gradeSign(1) ,_gradeExecute(1) {
	this->_signed = false;
	return ;
}

Form::~Form( void ) {
	return ;
}

Form::Form(std::string name, int gSign, int gExec) : _name(name), _gradeSign(gSign), _gradeExecute(gExec) {
	this->_signed = false;
	return ;
}

Form::Form(Form const & src)  : _name(src._name), _gradeSign(src._gradeSign), _gradeExecute(_gradeExecute) {
	*this = src;
	return ;
}

Form&	Form::operator=(Form const & rhs) {
	if (this != &rhs) {
		this->_signed = rhs._signed;
	}
	return *this;
}

std::string	Form::getName( void ) const {
	return this->_name;	
}

bool	Form::getSigned( void ) const {
	return this->_signed;
}

int	Form::getGradeSign( void ) const {
	return this->_gradeSign;
}

int	Form::getGradeExectute( void ) const {
	return this->_gradeExecute;
}

void	Form::beSigned(Bureaucrat const & src) {
	if (src.getGrade() > this->_gradeSign)
		throw Form::GradeTooLowException();
	this->_signed = true;
	std::cout << src.getName() << " signed " << this->_name << std::endl;
	return ;
}

std::ostream& operator<<(std::ostream& o, Form const &rhs) {
	o << rhs.getName();
	if (rhs.getSigned())
		o << ", is signed";
	else
		o << ", is not signed";
	o << ", have to be at the grade " << rhs.getGradeSign() << " to sign!";
	o << ", have to be at the grade " << rhs.getGradeExectute() << " to execute!" << std::endl;
	return o;
}