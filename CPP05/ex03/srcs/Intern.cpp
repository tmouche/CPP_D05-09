/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche < tmouche@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:19:19 by thibaud           #+#    #+#             */
/*   Updated: 2024/11/22 15:34:28 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.class.hpp"
#include "ShrubberyCreationForm.class.hpp"
#include "RobotomyRequestForm.class.hpp"
#include "PresidentialPardonForm.class.hpp"
#include <iostream>

Intern::Intern( void ) {
	return ;
}

Intern::~Intern( void ) {
	return ;
}

Intern::Intern(Intern const & src) {
	*this = src;
	return ;
}

Intern& Intern::operator=(Intern const & rhs) {
	if (this != &rhs)
		return *this;
	return *this;
}

AForm*	Intern::makeForm(std::string nameForm, std::string target) {
	int const			nbForm = 3;
	std::string const	forms[nbForm] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	int					idx;

	for (idx = 0; idx < nbForm && forms[idx].compare(nameForm); idx++);
	if (idx < nbForm) {
		std::cout << "Intern creates " << forms[idx] << std::endl;
		switch (idx) {
			case 0:
				return new PresidentialPardonForm(target);
			case 1:
				return new RobotomyRequestForm(target);
			case 2:
				return new ShrubberyCreationForm(target);
		}
	}
	std::cout << "The form " << nameForm << " does not exist!" << std::endl;
	return NULL;
}
