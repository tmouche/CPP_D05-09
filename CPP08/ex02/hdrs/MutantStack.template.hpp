/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.template.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:20:04 by tmouche           #+#    #+#             */
/*   Updated: 2025/02/06 18:47:05 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TEMPLATE_HPP
# define MUTANTSTACK_TEMPLATE_HPP
# include <stack>

template <typename T>

class MutantStack : public std::stack<T>
{
public:

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	MutantStack() {};
	iterator begin() {return this->c.begin();}
	iterator end() {return this->c.end();}

	const_iterator begin() const {return this->c.begin();}
	const_iterator end() const {return this->c.end();}

};

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
