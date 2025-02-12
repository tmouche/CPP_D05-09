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
#include "Exception.hpp"
#include <iostream>
#include <limits>
#include <cstdlib>

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
	if (this != &rhs)
		return *this;
	return *this;
}

double	DoubleConverter::converter(std::string const src) {
	double				doubleConverted;

	try {
		doubleConverted = std::atof(src.c_str());
	}
	catch (std::exception const & e) {
		throw NoConvertionException();
	}
	return doubleConverted;
}
