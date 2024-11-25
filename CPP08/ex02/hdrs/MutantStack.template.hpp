/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.template.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:20:04 by tmouche           #+#    #+#             */
/*   Updated: 2024/10/01 11:55:35 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TEMPLATE_HPP
# define MUTANTSTACK_TEMPLATE_HPP
# include <stack>

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

	bool	empty( void ) const {
		return this->myStack.empty();
	}

	sizet	size( void ) const {
		return this->myStack.size();
	}

	T&	top( void ) const {
		return this->myStack.top();
	}

	void	push(T const & value) {
		this->myStack.push(value);
		return ;
	}

	void	emplace(T&& value) {
		return this->myStack.emplace(value);
	}

	void	pop( void ) {
		this->myStack->pop();
		return ;
	}

	void	swap(std::stack<T> const & value) {
		this->myStack.swap(value);
		return ;
	}

	
	
private :
	std::stack<T>	myStack;
};

#endif
