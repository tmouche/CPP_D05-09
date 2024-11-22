/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntConverter.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche < tmouche@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:04:18 by tmouche           #+#    #+#             */
/*   Updated: 2024/11/22 16:23:59 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IntConverter.class.hpp"
#include <iostream>
#include <cstdlib>

IntConverter::IntConverter( void ) {
	return ;
}

IntConverter::~IntConverter( void ) {
	return ;
}

IntConverter::IntConverter(IntConverter const & src) {
	*this = src;
	return ;
}

IntConverter&	IntConverter::operator=(IntConverter const & rhs) {
	if (this != &rhs)
		return *this;
	return *this;
}

int	IntConverter::converter(std::string const src) {
	int				intConverted;

	try {
		intConverted = std::atoi(src.c_str());
	}
	catch (std::invalid_argument const & e) {
		throw IntConverter::NoConvertionException();
	}
	catch (std::out_of_range const & e) {
		throw IntConverter::NoConvertionException();
	}
	return intConverted;
}
