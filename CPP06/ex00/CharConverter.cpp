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

char	CharConverter::convert(std::string src) {
	int	const	intConverted = std::stoi(src);
	char const	c = static_cast<char>(intConverted);

	if (intConverted < 32 || intConverted > 256)
		std::cout << "impossible" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;
	return c;
}
