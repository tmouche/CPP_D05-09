/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 05:30:12 by thibaud           #+#    #+#             */
/*   Updated: 2024/09/18 06:30:29 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.class.hpp"
#include "A.class.hpp"
#include "B.class.hpp"
#include "C.class.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base*	generate( void ) {
	int	random;

	srand(time(NULL));
	random = rand() % 3;
	switch (random) {
		case 0 :
			return new A();
		case 1 :
			return new B();
		case 2 :
			return new C();
	}
	return NULL;
}

void	identify(Base* p) {
	Base const *	const tab[3] = {dynamic_cast<A*>(p), dynamic_cast<B*>(p), dynamic_cast<C*>(p)};
	int				idx;

	for (idx = 0; idx < 3 && !tab[idx]; idx++);
	switch (idx) {
		case 0 :
			std::cout << "The actual type is A" << std::endl;
			return ;
		case 1 :
			std::cout << "The actual type is B" << std::endl;
			return ;
		case 2 :
			std::cout << "The actual type is C" << std::endl;
			return ;
	}
	return ;
}

void	identify(Base& p) {
	try {
		A&	refACast = dynamic_cast<A&>(p);
	}
	catch (std::bad_cast const & e) {
		try {
			B&	refBCast = dynamic_cast<B&>(p);
		}
		catch (std::bad_cast const & e) {
			try {
				C&	refBCast = dynamic_cast<C&>(p);
			}
			catch (std::bad_cast const & e) {
				std::cout << "Unrecognized type" << std::endl;
				return ;
			}
			std::cout << "The actual type is C" << std::endl;
			return ;
		}
		std::cout << "The actual type is B" << std::endl;
		return ;
	}
	std::cout << "The actual type is A" << std::endl;
	return ;
}

int	main( void ) {
	Base*	ptrRand = generate();
	Base*	ptrDefinedA = new A();
	Base*	ptrDefinedB = new B();
	Base*	ptrDefinedC = new C();
	A		refA; 
	B		refB;
	C		refC;

	std::cout << "identify ptrRand: ";
	identify(ptrRand);
	std::cout << "identify ptrDefinedB: ";
	identify(ptrDefinedB);
	std::cout << "identify ptrDefinedA: ";
	identify(ptrDefinedA);
	std::cout << "identify ptrDefinedC: ";
	identify(ptrDefinedC);
	std::cout << "identify refB: ";
	identify(refB);
	std::cout << "identify refA: ";
	identify(refA);
	std::cout << "identify refC: ";
	identify(refC);
	delete ptrRand;
	delete ptrDefinedA;
	delete ptrDefinedB;
	delete ptrDefinedC;
	return 0;
}