/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:42:14 by tmouche           #+#    #+#             */
/*   Updated: 2024/09/25 12:41:35 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.class.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>


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

	std::vector<int>					vecRef;
	Span								itTest(10);
	
	for (int idx = 0; idx < 12000; idx++)
		vecRef.push_back(idx);
	std::vector<int>::const_iterator	itBegin = vecRef.begin();
	std::vector<int>::const_iterator	itTen = vecRef.begin();
	for (int count = 0; count < 10; count++)
		itTen++;
	itTest.addNumber(itBegin, itTen);
	resShortest = numbers.shortestSpan();
	std::cout << "The shortest span is " << resShortest << std::endl;
	resLongest = numbers.longestSpan();
	std::cout << "The longest span is " << resLongest << std::endl;
	
	std::cout << "*** * * * Subject Main Test * * * ***" << std::endl;

	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	resShortest = sp.shortestSpan();
	std::cout << "The shortest span is " << resShortest << std::endl;
	resLongest = sp.longestSpan();
	std::cout << "The longest span is " << resLongest << std::endl;

	std::cout << "*** * * * 10k random Test * * * ***" << std::endl;

	Span mySpan = Span(10000);

	for (int i = 0; i < 10000; i++) {
		srand(time(NULL) + i);
		int random = rand() % 10000;
		mySpan.addNumber(random);
	}
	resShortest = mySpan.shortestSpan();
	std::cout << "The shortest span is " << resShortest << std::endl;
	resLongest = mySpan.longestSpan();
	std::cout << "The longest span is " << resLongest << std::endl;
	return 0;
}
