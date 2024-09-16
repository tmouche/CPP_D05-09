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
	return *this;
}

bool	DoubleConverter::itsDouble(std::string src) {
	return ;
}
