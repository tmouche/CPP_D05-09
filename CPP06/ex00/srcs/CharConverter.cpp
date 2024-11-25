/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharConverter.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche < tmouche@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:04:18 by tmouche           #+#    #+#             */
/*   Updated: 2024/11/22 16:23:41 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CharConverter.class.hpp"
#include <iostream>
#include <cstdlib>

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
	if (this != &rhs)
		return *this;
	return *this;
}

char	CharConverter::converter(std::string const src){
	int		intConverted;
	char	c;

	try {
		intConverted = std::atoi(src.c_str());
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
