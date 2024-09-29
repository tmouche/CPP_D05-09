/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.template.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:20:04 by tmouche           #+#    #+#             */
/*   Updated: 2024/09/29 18:54:54 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TEMPLATE_HPP
# define MUTANTSTACK_TEMPLATE_HPP

template <typename T>
class MutantStack {
public :
	MutantStack( void ) {}
	~MutantStack( void ) {}
	MutantStack(MutantStack const & src) {
		*this = src;
		return ;
	}
	
	MutantStack&	operator=(MutantStack const & rhs) {
		if (this != &rhs) {
			
		}
		return *this;
	}
};

#endif
