/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:53:39 by tmouche           #+#    #+#             */
/*   Updated: 2024/10/16 18:50:27 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.class.hpp"
#include <iostream>

PmergeMe::PmergeMe( void ) : _arraySize(0) {
	return ;
}

PmergeMe::PmergeMe(int const * array, int const arraySize) : _arraySize(arraySize) {
	std::cout << "Before:	";
	for (int idx = 0; idx < arraySize; idx++) {
		std::cout << " " << array[idx];
		this->_myVector.push_back(array[idx]);
	}
	std::cout << std::endl;
	// this->_myVectorContainer = new std::vector<std::vector<int>&>();
	return ;
}

PmergeMe::~PmergeMe( void ) {
	return ;
}

PmergeMe::PmergeMe(PmergeMe const & src) : _arraySize(src._arraySize) {
	*this = src;	
	return ;
}

PmergeMe&	PmergeMe::operator=(PmergeMe const & rhs) {
	if (this != &rhs) {
		this->_myVector = rhs._myVector;
	}
	return *this;
}

void	PmergeMe::mergeVector( void ) {
	int	containerSize = this->_myVectorContainer.size();

	if (containerSize == 1)
		return ;
	std::vector<int>*	vectorContainer = new std::vector<int>();
	for (int idx = 0; )
}

void	PmergeMe::divideVector(std::vector<int> const & numerator) {
	int	numeratorSize = numerator.size();

	if (numeratorSize <= 1)
		return ;
	std::vector<int>*	vectorContainer[2] = {new std::vector<int>(), new std::vector<int>()};
	for (int i = 0; i < numeratorSize; i++) {
		vectorContainer[i % 2 == 0 ? 0 : 1]->push_back(numerator[i]); 
	}
	if (!this->_myVectorContainer.empty())
		this->_myVectorContainer.pop_back();
	this->_myVectorContainer.push_back(vectorContainer[0]);
	divideVector(*this->_myVectorContainer.back());
	this->_myVectorContainer.push_back(vectorContainer[1]);
	divideVector(*this->_myVectorContainer.back());
	return ;
}

void	PmergeMe::vectorSortMyNumber( void ) {
	divideVector(this->_myVector);
	mergeVector();
	return ;
}

void	PmergeMe::doubleSortMyNumber( void ) {
	this->vectorSortMyNumber();
	std::cout << "after:	";
	// for (int idx = 0; idx < this->_arraySize; idx++) {
	// 	std::cout << " " << this->_myVector[idx];
	// }
	for (int idx = 0; idx < this->_arraySize; idx++) {
		std::cout << " " << this->_myVectorContainer[idx]->back();
	}
	std::cout << std::endl;
	this->_VectorTime = 1;
	return ;
}

