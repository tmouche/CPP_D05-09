/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntConverter.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:04:18 by tmouche           #+#    #+#             */
/*   Updated: 2024/09/16 13:10:22 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IntConverter.class.hpp"

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
	return *this;
}

bool	IntConverter::itsChar(std::string src) {
	return ;
}
