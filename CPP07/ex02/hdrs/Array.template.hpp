/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.template.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 07:20:33 by thibaud           #+#    #+#             */
/*   Updated: 2025/02/20 16:37:29 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TEMPLATE_HPP
# define ARRAY_TEMPLATE_HPP
# include <exception>

class OutOfBound : public std::exception {
	const char* what( void ) const throw() {
		return ("out of bound");
	}
};

template< typename T >
class Array {
public :
	Array( void ) {}	
	~Array( void ) {
		delete [] this->_myArray;
		return ;
	}
	Array(unsigned int n) : _arraySize(n) {
		this->_myArray = new T[n];
	};
	Array(Array const & src) : _arraySize(src._arraySize) {
		*this = src;
		return ;
	}

	Array&	operator=(Array const & rhs) {
		if (this != &rhs) {
			this->_myArray = new T[this->_arraySize];
			for (unsigned int idx = 0; idx < this->_arraySize; idx++)
				this->_myArray[idx] = rhs._myArray[idx];
		}
		return *this;
	}
	T&	operator[](unsigned int const & rhs) const {
		if (rhs >= this->_arraySize)
			throw OutOfBound();
		return (this->_myArray[rhs]);
	}

	unsigned int	size( void ) const {
		return this->_arraySize;
	}

private :
	T*					_myArray;
	unsigned int const	_arraySize;
}; 

#endif
