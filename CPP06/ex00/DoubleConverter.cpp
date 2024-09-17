/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DoubleConverter.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:04:18 by tmouche           #+#    #+#             */
/*   Updated: 2024/09/16 13:11:33 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DoubleConverter.class.hpp"
#include <iostream>
#include <limits>
#include <cmath>

DoubleConverter::DoubleConverter( void ) {
	return ;
}

DoubleConverter::~DoubleConverter( void ) {
	return ;
}

DoubleConverter::DoubleConverter(DoubleConverter const & src) {
	*this = src;
	return ;
}

DoubleConverter&	DoubleConverter::operator=(DoubleConverter const & rhs) {
	return *this;
}

double	DoubleConverter::converter(std::string src) {
	double				doubleConverted;
	std::string const	specialSrc[3] = {"-inf", "+inf", "nan"};
	int					idx;

	for (idx = 0; idx < 3 && specialSrc[idx].compare(src); idx++);
	switch (idx) {
		case 0 :
			doubleConverted = __DBL_MIN__;
			std::cout << "-inf" << std::endl;
		case 1 :
			doubleConverted = __DBL_MAX__;
			std::cout << "+inf" << std::endl;
		case 2 :
			doubleConverted = std::nan("");
			std::cout << "nan" << std::endl;
		default :
			try {
				doubleConverted = std::stod(src);
			}
			catch (std::invalid_argument const & e) {
				std::cout << "impossible" << std::endl;
				return std::nan("");
			}
			catch (std::out_of_range const & e) {
				std::cout << "impossible" << std::endl;
				return  std::nan("");
			}
			std::cout << doubleConverted << std::endl;
	}
	return doubleConverted;
}
