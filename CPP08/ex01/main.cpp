/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:42:14 by tmouche           #+#    #+#             */
/*   Updated: 2024/09/24 17:55:42 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.class.hpp"
#include <iostream>

int	main( void ) {
	Span	numbers(10);
	unsigned int	resShortest, resLongest;

	try {
		for (int idx = 0; idx < 11; idx++)
			numbers.addNumber(idx);
	}
	catch (Span::NoSuchSpaceLeftException& e) {
		std::cout << e.what() << std::endl;
		return 0;
	}
	try {
		resShortest = numbers.shortestSpan();
		std::cout << "The shortest span is " << resShortest << std::endl;
	}
	catch (Span::NotEnoughElementException& e) {
		std::cout << e.what() << std::endl;
		return 0;
	}
	try {
		resLongest = numbers.longestSpan();
		std::cout << "The longest span is " << resLongest << std::endl;
	}
	catch (Span::NotEnoughElementException& e) {
		std::cout << e.what() << std::endl;
		return 0;
	}
	return 1;
}
