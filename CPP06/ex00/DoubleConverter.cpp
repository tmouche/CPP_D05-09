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

double	DoubleConverter::converter(std::string const src) {
	double				doubleConverted;
	std::streamsize		ss = std::cout.precision();

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
	std::cout.precision(2);
	std::cout << std::fixed << doubleConverted << std::endl;
	std::cout.precision(ss);
	return doubleConverted;
}
