/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:24:54 by tmouche           #+#    #+#             */
/*   Updated: 2025/02/12 16:09:08 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.class.hpp"
#include "CharConverter.class.hpp"
#include "IntConverter.class.hpp"
#include "FloatConverter.class.hpp"
#include "DoubleConverter.class.hpp"
#include "Exception.hpp"
#include <iostream>

ScalarConverter::ScalarConverter( void ) {
	return ;
}

ScalarConverter::~ScalarConverter( void ) {
	return ;
}

ScalarConverter::ScalarConverter(ScalarConverter const & src) {
	*this = src;
	return ;
}

ScalarConverter&	ScalarConverter::operator=(ScalarConverter const & rhs) {
	if (this != &rhs)
		return *this;
	return *this;
}

void	ScalarConverter::convert(std::string input) {
	std::streamsize		ss = std::cout.precision();
	char	c;
	int		i;
	float	f;
	double	d;

	std::cout << "char: ";
	try {
		c = CharConverter::converter(input);
		std::cout << c << std::endl;
	}
	catch (std::exception const & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "int: ";
	try {
		i = IntConverter::converter(input);
		std::cout << i << std::endl;
	}
	catch (std::exception const & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout.precision(2);
	std::cout << "float: ";
	try {
		f = FloatConverter::converter(input);
		std::cout << std::fixed << f << "f" << std::endl;
	}
	catch (std::exception const & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "double: ";
	try {
		d = DoubleConverter::converter(input);
		std::cout << std::fixed << d << std::endl;
	}
	catch (std::exception const & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout.precision(ss);
	return ;
}
