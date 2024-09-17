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
#include <iomanip>
#include <ios>
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

float	FloatConverter::converter(std::string const src) {
	float				floatConverted;
	std::streamsize		ss = std::cout.precision();

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
	std::cout.precision(2);
	std::cout << std::fixed << floatConverted << "f" <<std::endl;
	std::cout.precision(ss);
	return floatConverted;
}
