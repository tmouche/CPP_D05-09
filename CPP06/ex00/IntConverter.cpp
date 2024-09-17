/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntConverter.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:04:18 by tmouche           #+#    #+#             */
/*   Updated: 2024/09/17 06:56:19 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IntConverter.class.hpp"
#include <iostream>
#include <cmath>

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

int	IntConverter::converter(std::string src) {
	std::cout << std::endl;
	return 0;
}
