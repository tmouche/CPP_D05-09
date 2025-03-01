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
#include <limits>

Span::Span( void ) {
	return ;
}

Span::~Span( void ) {
	return ;	
}

Span::Span(unsigned int N) {
	std::vector<int>* myVector = new std::vector<int>();
	
	this->_myVector = myVector;
	this->_countDownSize = N;
	return ;
}

Span::Span(Span const & src) {
	*this = src;
	return ;
}

Span&	Span::operator=(Span const & rhs) {
	if (this != &rhs) {
		this->_myVector = rhs._myVector;
	}
	return *this;
}

void	Span::addNumber(int num) {
	if (this->_countDownSize > 0) {
		this->_myVector->push_back(num);
		--this->_countDownSize;
	}
	else
		throw Span::NoSuchSpaceLeftException();
	return ;
}

void	Span::addNumber(std::vector<int>::const_iterator start, std::vector<int>::const_iterator end) {
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
	std::vector<int>::const_iterator it;
	int					max = 0;
	int					min;

	if (this->_myVector->size() < 2)
		throw Span::NotEnoughElementException();
	min = this->_myVector->at(0);
	for (it = this->_myVector->begin(); it != this->_myVector->end(); it++) {
		if (*it > max)
			max = *it;
		else if (*it < min)
			min = *it;
	}
	return (max - min);
}

unsigned int	Span::shortestSpan( void ) const {
	std::vector<int>::const_iterator	it;
	int									min, minNext;

	if (this->_myVector->size() < 2)
		throw Span::NotEnoughElementException();
	min = *this->_myVector->begin();
	minNext = __INT_MAX__;
	for (it = this->_myVector->begin(); it != this->_myVector->end(); it++) {
		if (*it <= min)
			min = *it;
		else if (*it < minNext)
			minNext = *it;
	}
	return (minNext - min);
}

std::string	Span::NoSuchSpaceLeftException::what( void ) const throw() {
	return "The Vector is Full";
}

std::string	Span::NotEnoughElementException::what( void ) const throw() {
	return "Not enough element in the vector";
}