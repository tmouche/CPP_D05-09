/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharConverter.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:04:18 by tmouche           #+#    #+#             */
/*   Updated: 2024/09/16 13:11:33 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CharConverter.class.hpp"

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

bool	CharConverter::itsChar(std::string src) {
	return ;
}
