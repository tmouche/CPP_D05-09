/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:06:37 by tmouche           #+#    #+#             */
/*   Updated: 2024/11/19 16:30:47 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.template.hpp"
#include <iostream>
#include <vector>
#include <deque>

bool	checkData(char **data, std::string corpus) {
	for (int str = 0; data[str]; str++) {
		for (int idx = 0; data[str][idx]; idx++) {
			int idx_corpus;
			for (idx_corpus = 0; corpus[idx_corpus]; idx_corpus++) {
				if (data[str][idx] == corpus[idx_corpus])
					break ;
			}
			if (!corpus[idx_corpus])
				return false;
		}
	}
	return true ;
}

int	main(int ac, char **av) {
	(void)ac;

	if (ac < 2 || !checkData(&av[1], "0123456789")) {
		std::cout << "Bad Argument" << std::endl;
		return 1;
	}
	PmergeMe<std::vector<std::vector<int>*>, std::vector<int> >	testVector(&av[1]);
	std::vector<int> resVector = *testVector.SortMyNumbers();
	int const	sizeVector = resVector.size();
	std::cout << "Vec sorted: ";
	for (int idx = 0; idx < sizeVector; idx++) {
		std::cout << resVector[idx] << ", ";
	}
	std::cout << std::endl;

	PmergeMe<std::deque<std::deque<int>*>, std::deque<int> > testDeque(&av[1]);
	std::deque<int> resDeque = *testDeque.SortMyNumbers();
	int const	sizeDeque = resDeque.size();
	std::cout << "Deque sorted: ";
	for (int idx = 0; idx < sizeDeque; idx++) {
		std::cout << resDeque[idx] << ", ";
	}
	std::cout << std::endl;
	return 1;
}