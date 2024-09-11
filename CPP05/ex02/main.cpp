/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:30:24 by thibaud           #+#    #+#             */
/*   Updated: 2024/09/11 16:51:10 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.class.hpp"
#include "PresidentialPardonForm.class.hpp"
#include "RobotomyRequestForm.class.hpp"
#include "ShrubberyCreationForm.class.hpp"
#include "AForm.class.hpp"
#include <iostream>

int	main( void ) {

	Bureaucrat	aKid("Meg", 3);
	Bureaucrat	fKid("Chris", 148);
	AForm*		newForm = new PresidentialPardonForm("Chris");
	AForm*		form1 = new RobotomyRequestFarm("Chris");
	AForm*		form2 = new ShrubberyCreationForm("Home");

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
	aKid.executeForm(*newForm);
	fKid.signForm(*newForm);
	aKid.signForm(*newForm);
	aKid.executeForm(*newForm);
	aKid.signForm(*form1);
	aKid.executeForm(*form1);
	aKid.signForm(*form2);
	aKid.executeForm(*form2);
	delete newForm;
	delete form1;
	delete form2;
	return 0;
}