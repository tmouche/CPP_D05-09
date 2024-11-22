/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche < tmouche@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 04:36:59 by thibaud           #+#    #+#             */
/*   Updated: 2024/11/22 16:41:52 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.class.hpp"

Serializer::Serializer( void ) {
	return ;
}

Serializer::~Serializer( void ) {
	return ;
}

Serializer::Serializer(Serializer const & src) {
	*this = src;
	return ;
}

Serializer&	Serializer::operator=(Serializer const & rhs) {
	if (this != &rhs)
		return *this;
	return *this;
}

uintptr_t	Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}