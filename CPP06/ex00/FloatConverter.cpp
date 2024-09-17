/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FloatConverter.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:04:18 by tmouche           #+#    #+#             */
/*   Updated: 2024/09/16 13:11:33 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FloatConverter.class.hpp"
#include <iostream>
#include <cmath>

FloatConverter::FloatConverter( void ) {
	return ;
}

FloatConverter::~FloatConverter( void ) {
	return ;
}

FloatConverter::FloatConverter(FloatConverter const & src) {
	*this = src;
	return ;
}

FloatConverter&	FloatConverter::operator=(FloatConverter const & rhs) {
	return *this;
}

float	FloatConverter::converter(std::string src) {
	float				floatConverted;
	std::string const	specialSrc[3] = {"-inff", "+inff", "nanf"};
	int					idx;

	for (idx = 0; idx < 3 && specialSrc[idx].compare(src); idx++);
	switch (idx) {
		case 0 :
			floatConverted = __FLT_MIN__;
			std::cout << "-inff" << std::endl;
		case 1 :
			floatConverted = __FLT_MAX__;
			std::cout << "+inff" << std::endl;
		case 2 :
			floatConverted = std::nanf("");
			std::cout << "nanf" << std::endl;
		default :
			try {
				floatConverted = std::stof(src);
			}
			catch (std::invalid_argument const & e) {
				std::cout << "impossible" << std::endl;
				return std::nanf("");
			}
			catch (std::out_of_range const & e) {
				std::cout << "impossible" << std::endl;
				return  std::nanf("");
			}
			std::cout << floatConverted << std::endl;
	}
	return floatConverted;
}
