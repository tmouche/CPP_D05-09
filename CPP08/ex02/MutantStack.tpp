/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:11:43 by tmouche           #+#    #+#             */
/*   Updated: 2024/09/25 13:47:36 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.template.hpp"

MutantStack::MutantStack( void ) {
	return ;
}

MutantStack::~MutantStack( void ) {
	return ;
}

MutantStack::MutantStack(MutantStack const & src) {
	*this = src;
	return ;
}

MutantStack&	MutantStack::operator=(MutantStack const & rhs) {
	if (this != &rhs) {
		
	}
	return *this;
	
}