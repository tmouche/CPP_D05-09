/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharConverter.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:04:18 by tmouche           #+#    #+#             */
/*   Updated: 2024/09/17 06:59:00 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CharConverter.class.hpp"
#include <iostream>

CharConverter::CharConverter( void ) {
	return ;
}

CharConverter::~CharConverter( void ) {
	return ;
}

CharConverter::CharConverter(CharConverter const & src) {
	*this = src;
	return ;
}

CharConverter&	CharConverter::operator=(CharConverter const & rhs) {
	return *this;
}

char	CharConverter::converter(std::string const src){
	int		intConverted;
	char	c;

	try {
		intConverted = std::stoi(src);
	}
	catch (std::invalid_argument const & e) {
		throw CharConverter::NoConvertionException();
	}
	catch (std::out_of_range const & e) {
		throw CharConverter::NoConvertionException();
	}
	if (intConverted < 32 || intConverted > 126)	
		throw CharConverter::NoDisplayableException();
	c = static_cast<char>(intConverted);
	return c;
}
