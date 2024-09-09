/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:02:53 by thibaud           #+#    #+#             */
/*   Updated: 2024/09/09 20:22:55 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.class.hpp"
#include <iostream>

int	main( void ) {

	Bureaucrat	aKid("Meg", 3);
	Bureaucrat	fKid("Chris", 148);

	std::cout << "The first bureaucrat is " << aKid.getName() << " and her grade is " << aKid.getGrade() << "!" << std::endl;
	std::cout << "The second bureaucrat is " << fKid.getName() << " and his grade is " << fKid.getGrade() << "!" << std::endl;
	std::cout << aKid.getName() << " increment Grade!" << std::endl;
	aKid.incrementGrade();
	aKid.incrementGrade();
	aKid.incrementGrade(); //should catch an exception
	std::cout << aKid.getName() << " new grade is " << aKid.getGrade() << "!" << std::endl;
	std::cout << fKid.getName() << " increment Grade!" << std::endl;
	fKid.decrementGrade();
	fKid.decrementGrade();
	fKid.decrementGrade(); //should catch an exception
	std::cout << fKid.getName() << " new grade is " << fKid.getGrade() << "!" << std::endl;
	return 0;
}