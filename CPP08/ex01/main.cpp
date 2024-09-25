/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:42:14 by tmouche           #+#    #+#             */
/*   Updated: 2024/09/25 12:10:49 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.class.hpp"
#include <iostream>

int	main( void ) {
	Span	numbers(10);
	unsigned int	resShortest, resLongest;

	for (int idx = 0; idx < 10; idx++)
		numbers.addNumber(idx);
	resShortest = numbers.shortestSpan();
	std::cout << "The shortest span is " << resShortest << std::endl;
	resLongest = numbers.longestSpan();
	std::cout << "The longest span is " << resLongest << std::endl;

	Span	numFail(1);

	numFail.addNumber(1);
	try {
		numFail.addNumber(2);
	}
	catch (Span::NoSuchSpaceLeftException& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		numFail.longestSpan();
	}
	catch (Span::NotEnoughElementException& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		numFail.shortestSpan();
	}
	catch (Span::NotEnoughElementException& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "*** * * * Subject Main Test * * * ***" << std::endl;

	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}
