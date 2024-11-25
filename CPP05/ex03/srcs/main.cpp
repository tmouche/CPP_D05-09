/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:30:24 by thibaud           #+#    #+#             */
/*   Updated: 2024/09/11 18:45:10 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.class.hpp"
#include "PresidentialPardonForm.class.hpp"
#include "RobotomyRequestForm.class.hpp"
#include "ShrubberyCreationForm.class.hpp"
#include "AForm.class.hpp"
#include "Intern.class.hpp"
#include <iostream>

int	main( void ) {

	Bureaucrat	aKid("Meg", 3);
	Bureaucrat	fKid("Chris", 148);
	Intern		tasker;

	std::cout << aKid << std::endl;
	std::cout << fKid << std::endl;
	std::cout << aKid.getName() << " increment Grade!" << std::endl;
	aKid.incrementGrade();
	aKid.incrementGrade();
	aKid.incrementGrade(); //should catch an exception
	std::cout << aKid << std::endl;
	std::cout << fKid.getName() << " increment Grade!" << std::endl;
	fKid.decrementGrade();
	fKid.decrementGrade();
	fKid.decrementGrade(); //should catch an exception
	std::cout << fKid << std::endl;
	AForm*	PPF = tasker.makeForm("PresidentialPardonForm", "Chris");
	AForm*	RRF = tasker.makeForm("RobotomyRequestForm", "Chris");
	AForm*	SCF = tasker.makeForm("ShrubberyCreationForm", "Home");
	aKid.executeForm(*PPF); //should catch an exception
	fKid.signForm(*PPF); //should catch an exception
	aKid.signForm(*PPF);
	aKid.executeForm(*PPF);
	aKid.signForm(*RRF);
	aKid.executeForm(*RRF);
	aKid.signForm(*SCF);
	aKid.executeForm(*SCF);
	delete PPF;
	delete RRF;
	delete SCF;
	return 0;
}