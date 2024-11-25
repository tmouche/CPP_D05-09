/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:02:53 by thibaud           #+#    #+#             */
/*   Updated: 2024/09/09 21:19:43 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.class.hpp"
#include <iostream>

int	main( void ) {

	Bureaucrat	aKid("Meg", 3);
	Bureaucrat	fKid("Chris", 148);

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
	return 0;
}