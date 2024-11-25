/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:02:53 by thibaud           #+#    #+#             */
/*   Updated: 2024/09/11 16:30:52 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.class.hpp"
#include "Form.class.hpp"
#include <iostream>

int	main( void ) {

	Bureaucrat	aKid("Meg", 3);
	Bureaucrat	fKid("Chris", 148);
	Form		newForm("Firing Chris", 1, 1);

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
	aKid.signForm(newForm);
	fKid.signForm(newForm);
	return 0;
}