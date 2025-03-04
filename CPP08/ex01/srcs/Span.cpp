/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:44:34 by tmouche           #+#    #+#             */
/*   Updated: 2024/09/25 12:29:09 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.class.hpp"
#include <iostream>
#include <climits>

Span::Span( void ) : _size(0) {
	return ;
}

Span::~Span( void ) {
	return ;	
}

Span::Span(unsigned int N) : _size(N) {	
	return ;
}

Span::Span(Span const & src) : _size(src._size){
	*this = src;
	return ;
}

Span&	Span::operator=(Span const & rhs) {
	if (this != &rhs) {
		
	}
	return *this;
}

unsigned int	defSpan(int,int);

void	Span::addNumber(int const num) {
	if (this->_myVector.size() < this->_size)
		this->_myVector.push_back(num);
	else
		throw Span::NoSuchSpaceLeftException();
	return ;
}

void	Span::addNumber(spanIterator start, spanIterator end) {
	while (start != end) {
		try {
			this->addNumber(*start);
			++start;
		}
		catch (Span::NoSuchSpaceLeftException& e) {
			throw Span::NoSuchSpaceLeftException();
		}
	}
	return ;
}

unsigned int	Span::longestSpan( void ) const {
	unsigned int	longest = 0;

	if (this->_myVector.size() < 2)
		throw Span::NotEnoughElementException();
	spanIterator	actual = this->_myVector.begin();
	for (spanIterator next = actual + 1; next != this->_myVector.end(); actual++, next++) {
		unsigned int const	actualSpan = defSpan(*actual, *next);
		if (actualSpan > longest)
			longest = actualSpan;
	}
	return longest;
}

unsigned int	Span::shortestSpan( void ) const {
	unsigned int	shortest = UINT_MAX;

	if (this->_myVector.size() < 2)
		throw Span::NotEnoughElementException();
	spanIterator	actual = this->_myVector.begin();
	for (spanIterator next = actual + 1; next != this->_myVector.end(); actual++, next++) {
		unsigned int const	actualSpan = defSpan(*actual, *next);
		if (actualSpan < shortest)
			shortest = actualSpan;
	}
	return shortest;
}

std::string	Span::NoSuchSpaceLeftException::what( void ) const throw() {
	return "The Vector is Full";
}

std::string	Span::NotEnoughElementException::what( void ) const throw() {
	return "Not enough element in the vector";
}

unsigned int	defSpan(int num1, int num2) {
	if (num1 > num2)
		return num1 - num2;
	return num2 - num1;
}