/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:24:54 by tmouche           #+#    #+#             */
/*   Updated: 2024/09/17 06:52:57 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.class.hpp"
#include "CharConverter.class.hpp"
#include "IntConverter.class.hpp"
#include "FloatConverter.class.hpp"
#include "DoubleConverter.class.hpp"
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
	return *this;
}

void	ScalarConverter::convert(std::string input) {
	std::cout << "char :";
	CharConverter::convert(input);
	std::cout << "int :";
	IntConverter::converter(input);
	std::cout << "float :";
	FloatConverter::converter(input);
	std::cout << "double :";
	DoubleConverter::converter(input);
	return ;
}
