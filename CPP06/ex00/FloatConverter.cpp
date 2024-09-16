/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FloatConverter.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:04:18 by tmouche           #+#    #+#             */
/*   Updated: 2024/09/16 13:11:33 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FloatConverter.class.hpp"

FloatConverter::FloatConverter( void ) {
	return ;
}

FloatConverter::~FloatConverter( void ) {
	return ;
}

FloatConverter::FloatConverter(FloatConverter const & src) {
	*this = src;
	return ;
}

FloatConverter&	FloatConverter::operator=(FloatConverter const & rhs) {
	return *this;
}

bool	FloatConverter::itsFloat(std::string src) {
	return ;
}
