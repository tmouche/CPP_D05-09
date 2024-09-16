/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:24:54 by tmouche           #+#    #+#             */
/*   Updated: 2024/09/16 12:59:38 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.class.hpp"

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
	if (CharConverter::itsChar())
		
	
}
