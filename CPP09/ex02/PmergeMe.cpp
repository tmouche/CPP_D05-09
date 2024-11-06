/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:53:39 by tmouche           #+#    #+#             */
/*   Updated: 2024/11/06 19:24:13 by tmouche          ###   ########.fr       */
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

bool	PmergeMe::mergeSingleVector( void ) {
	std::vector<int>*	vectorContainer[2] = {new std::vector<int>(*this->_myVectorContainer.back()), NULL};

	this->_myVectorContainer.pop_back();
	if (this->_myVectorContainer.back()->size() < 2) {
		vectorContainer[1] = new std::vector<int>(*this->_myVectorContainer.back());
		this->_myVectorContainer.pop_back();
		int	idx = (vectorContainer[0]->back() - vectorContainer[1]->back() >= 0 ? 0 : 1);
		vectorContainer[idx]->push_back(vectorContainer[(idx + 1) % 2]->back());
		this->_myVectorContainer.insert(this->_myVectorContainer.begin(), vectorContainer[idx]);
		delete vectorContainer[(idx + 1) % 2];
	}
	else {
		this->_myVectorContainer.insert(this->_myVectorContainer.begin(), vectorContainer[0]);
		return 0;
	}
	return 1;
}

void	PmergeMe::binarySearch(std::vector<int> & vec, int num) {
	int const	size = vec.size();
	int			idx = size / 2;
	std::vector<int>::iterator	it;

	// std::cout << "num: " << num << " idx: " << idx << std::endl;
	if (size == 0) {
		vec.push_back(num);
		// std::cout << num << " first pushed" << std::endl;
		return ;
	}
	while (1) {
		if (idx == 0) {
			vec.insert(vec.begin(), num);
			return ;	
		}
		else if (idx == size - 1) {
			vec.push_back(num);
			
		}
		if (num >= vec[idx])
					
	}
}

void	PmergeMe::merger( void ) {
	int const	size = this->_myVectorContainer.size();
	std::vector<int>*	vectorContainer[2] = {new std::vector<int>(), new std::vector<int>()};

	for (int idx = 0; idx < size; idx++) {
		binarySearch(*vectorContainer[0], this->_myVectorContainer[idx]->front());
		if (this->_myVectorContainer[idx]->size() == 2)
			binarySearch(*vectorContainer[1], this->_myVectorContainer[idx]->back());
		// delete this->_myVectorContainer[idx];
	}
	for (int dec = size; dec > 0; dec--) {
		this->_myVectorContainer.pop_back();
	}
	this->_myVectorContainer.push_back(vectorContainer[0]);
	this->_myVectorContainer.push_back(vectorContainer[1]);
	std::cout << "done" << std::endl;
	return ;
}

// void	PmergeMe::insertAndSort(std::vector<std::vector<int>*> merge) {
	
// 	if (merge.front()->size() == 1)
// 		return ;
	
	
	
// 	return ;
// }

void	PmergeMe::divideVector(std::vector<int> const & numerator) {
	int	const numeratorSize = numerator.size();

	if (numeratorSize <= 1)
		return ;
	std::vector<int>*	vectorContainer[2] = {new std::vector<int>(), new std::vector<int>()};
	for (int i = 0; i < numeratorSize; i++) {
		vectorContainer[i % 2]->push_back(numerator[i]); 
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
	while (mergeSingleVector());
	return ;
}

void	PmergeMe::doubleSortMyNumber( void ) {
	this->vectorSortMyNumber();
	std::cout << "after:	";
	for (int idx = 0; idx < this->_arraySize; idx++) {
		std::cout << " " << this->_myVector[idx];
	}
	std::cout << std::endl;
	for (unsigned int idx = 0; idx < this->_myVectorContainer.size(); idx++) {
		std::cout << this->_myVectorContainer[idx]->front();
		if (this->_myVectorContainer[idx]->size() > 1) 
			std::cout << ", " << this->_myVectorContainer[idx]->back();
		std::cout << " | ";
	}
	std::cout << std::endl;
	merger();
	std::cout << "after merge big: ";
	std::vector<int> temp = *this->_myVectorContainer[0];
	for (unsigned int idx = 0; idx < temp.size(); idx++) {
		std::cout << temp[idx] << ", ";
	}
	std::cout << std::endl;
	std::cout << "after merge little: ";
	temp = *this->_myVectorContainer[1];
	for (unsigned int idx = 0; idx < temp.size(); idx++) {
		std::cout << temp[idx] << ", ";
	}
	std::cout << std::endl;
	this->_VectorTime = 1;
	return ;
} 
