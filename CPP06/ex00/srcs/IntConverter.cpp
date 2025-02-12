/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntConverter.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:04:18 by tmouche           #+#    #+#             */
/*   Updated: 2025/02/12 16:12:16 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IntConverter.class.hpp"
#include "Exception.hpp"
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
	catch (std::exception const & e) {
		throw NoConvertionException();
	}
	return intConverted;
}
