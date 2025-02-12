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
#include "Exception.hpp"
#include <iostream>
#include <iomanip>
#include <ios>
#include <cstdlib>

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
	if (this != &rhs)
		return *this;
	return *this;
}

float	FloatConverter::converter(std::string const src) {
	float				floatConverted;

	try {
		floatConverted = std::atof(src.c_str());
	}
	catch (std::exception const & e) {
		throw NoConvertionException();
	}
	return floatConverted;
}
