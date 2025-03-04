/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:42:24 by tmouche           #+#    #+#             */
/*   Updated: 2025/02/07 13:58:32 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/MutantStack.template.hpp"
#include <iostream>
#include <list>

int main( void ) {
	std::cout << "Starting MutantStack" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "list front: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "list size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "Starting List" << std::endl;
	std::list<int> myList;
	myList.push_back(5);
	myList.push_back(17);
	std::cout << "list front: " << myList.front() << std::endl;
	myList.pop_back();
	std::cout << "list size: " << myList.size() << std::endl;
	myList.push_back(3);
	myList.push_back(5);
	myList.push_back(737);
	myList.push_back(0);
	std::list<int>::iterator it_begin = myList.begin();
	std::list<int>::iterator it_end = myList.end();
	++it_begin;
	--it_begin;
	while (it_begin != it_end)
	{
		std::cout << *it_begin << std::endl;
		++it_begin;
	}
	return 0;
}