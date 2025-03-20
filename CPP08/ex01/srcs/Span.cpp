/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:44:34 by tmouche           #+#    #+#             */
/*   Updated: 2025/03/20 11:04:58 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.class.hpp"
#include <iostream>
#include <climits>
#include <algorithm>

Span::Span( void ) : _size(0) {
	this->_longest = 0;
	this->_shortest = UINT_MAX;
	return ;
}

Span::~Span( void ) {
	return ;
}

Span::Span(unsigned int N) : _size(N) {
	this->_longest = 0;
	this->_shortest = UINT_MAX;
	return ;
}

Span::Span(Span const & src) : _size(src._size){
	*this = src;
	return ;
}

Span&	Span::operator=(Span const & rhs) {
	if (this != &rhs) {
		this->_myVector = std::vector<int>(rhs._myVector);
		this->_longest = rhs._longest;
		this->_shortest= rhs._shortest;
	}
	return *this;
}


void	Span::addNumber(int const num) {
	unsigned int const	vecSize = this->_myVector.size();

	if (vecSize < this->_size) {
		this->_myVector.push_back(num);
		this->defSpan();
	}
	else
		throw Span::NoSuchSpaceLeftException();
	return ;
}

void	Span::addNumber(spanIterator start, spanIterator end) {
	while (start != end) {
		this->addNumber(*start);
		++start;
	}
	return ;
}

unsigned int	Span::longestSpan( void ) const {
	if (this->_myVector.size() < 2)
		throw Span::NotEnoughElementException();
	return this->_longest;
}

unsigned int	Span::shortestSpan( void ) const {
	if (this->_myVector.size() < 2)
		throw Span::NotEnoughElementException();
	return this->_shortest;
}

std::string	Span::NoSuchSpaceLeftException::what( void ) const throw() {
	return "The Vector is Full";
}

std::string	Span::NotEnoughElementException::what( void ) const throw() {
	return "Not enough element in the vector";
}

void	Span::defSpan( void ) {
	if (this->_myVector.size() < 2)
		return ;
	unsigned int const	span = std::abs(*(this->_myVector.end()-1) - *(this->_myVector.end()-2));
	if (span > this->_longest)
		this->_longest = span;
	if (span < this->_shortest)
		this->_shortest = span;
}