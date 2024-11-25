/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:46:06 by thibaud           #+#    #+#             */
/*   Updated: 2024/09/09 22:25:02 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.class.hpp"
#include "Form.class.hpp"

Bureaucrat::Bureaucrat( void ) {
	return ;
}

Bureaucrat::~Bureaucrat( void ) {
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) {
	*this = src;
	return ;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const & rhs) {
	if (this != &rhs) {
		this->_grade = rhs._grade;
		this->_name = rhs._name;
	}
	return *this;
}

Bureaucrat::Bureaucrat(std::string name, int grade) {
	this->_name = name;
	if (grade > 150)
		this->_grade = 150;
	else if (grade < 1)
		this->_grade = 1;
	else
		this->_grade = grade;
	return ;
}

std::string	Bureaucrat::getName( void ) const {
	return this->_name;
}

int	Bureaucrat::getGrade( void ) const {
	return this->_grade;
}

void	Bureaucrat::incrementGrade( void ) {
	try {
		if (this->_grade - 1 < 1)
			throw Bureaucrat::GradeTooHighException();
		else
			--this->_grade;
	}
	catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << "The actual grade is the highest so it can not be more increased!" << std::endl;
	}
	return ;
}

void	Bureaucrat::decrementGrade( void ) {
	try {
		if (this->_grade + 1 > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			++this->_grade;
	}
	catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << "The actual grade is the lowest so it can not be more increased!" << std::endl;
	}
	return ;
}

void	Bureaucrat::signForm(Form& src) {
	try {
		src.beSigned(*this);
	}
	catch (Form::GradeTooLowException &e) {
		std::cout << this->_name << " couldn't sign " << src.getName() << " because his grade is too low";
	}
	return ;
}

std::ostream& operator<<(std::ostream& o, Bureaucrat const &rhs) {
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return o;
}

