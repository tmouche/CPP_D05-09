/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:27:08 by tmouche           #+#    #+#             */
/*   Updated: 2025/03/31 21:04:28 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.class.hpp"
#include <cstdlib>


RPN::RPN( void ) {
	this->_fctPtr[0] = &RPN::addition;
	this->_fctPtr[1] = &RPN::subtraction;
	this->_fctPtr[2] = &RPN::multiplication;
	this->_fctPtr[3] = &RPN::division;
	return ;
}

RPN::~RPN( void ) {
	return ;
}

RPN::RPN(RPN const & src) {
	*this = src;
	return ;
}

RPN&	RPN::operator=(RPN const & rhs) {
	if (this != &rhs) {
		this->_myStack = rhs._myStack;
	}
	return *this;
}

void	RPN::number(std::string &data) {
	this->_myStack.push(std::atoi(data.c_str()));
	while (::isdigit(data[0]))
		data.erase(0, 1);
	return ;
}

void	RPN::space(std::string &data) {
	while (::isblank(data[0]))
		data.erase(0, 1);
	return ;
}

void	RPN::addition(int& temp) {
	temp = this->_myStack.top() + temp;
	return ;
}

void	RPN::subtraction(int& temp) {
	temp = this->_myStack.top() - temp;
	return ;
}

void	RPN::multiplication(int& temp) {
	temp = this->_myStack.top() * temp;
	return ;
}

void	RPN::division(int& temp) {
	temp = this->_myStack.top() / temp;
	return ;
}


bool	RPN::checkString(std::string const data, std::string const corpus) const {
	if (data.empty() || corpus.empty())
		return false;
	for (int idx = 0; data[idx]; idx++) {
			for (int idxCorpus = 0; true; idxCorpus++) {
				if (data[idx] == corpus[idxCorpus])
					break ;
				if (!corpus[idxCorpus + 1])
					return false;
		}
	}
	return true;
}

int	RPN::calculRPN(std::string data) {
	std::string const	corpus = "0123456789 +-*/";
	int					temp;
	int					idx;
	
	if (!checkString(data, corpus))
		throw std::exception();
	while (!data.empty()) {
		for (idx = 0; corpus[idx] && corpus[idx] != data[0]; idx++);
		if (idx <= 10)
			idx < 10 ? this->number(data) : this->space(data);
		else if (this->_myStack.size() > 1) {
			temp = this->_myStack.top();
			this->_myStack.pop();
			(this->*_fctPtr[idx - 11])(temp);
			this->_myStack.pop();
			this->_myStack.push(temp);
			data.erase(0, 1);
		}
		else
			throw std::exception();
	}
	if (this->_myStack.size() > 1)
		throw std::exception();	
	return (this->_myStack.top());
}