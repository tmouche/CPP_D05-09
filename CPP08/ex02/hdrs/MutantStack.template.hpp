/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.template.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:20:04 by tmouche           #+#    #+#             */
/*   Updated: 2025/02/07 18:21:59 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TEMPLATE_HPP
# define MUTANTSTACK_TEMPLATE_HPP
# include <stack>

template <typename T>

class MutantStack : public std::stack<T> {
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	MutantStack( void ) {return ;}
	~MutantStack( void ) {return ;}

	iterator begin( void ) {return this->c.begin();}
	iterator end( void ) {return this->c.end();}

	const_iterator begin( void ) const {return this->c.begin();}
	const_iterator end( void ) const {return this->c.end();}
};

#endif
