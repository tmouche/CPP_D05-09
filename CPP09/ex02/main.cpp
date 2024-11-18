/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:06:37 by tmouche           #+#    #+#             */
/*   Updated: 2024/11/18 17:40:32 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.template.hpp"
#include <iostream>
#include <vector>
#include <deque>

bool	checkData(std::string str, std::string corpus) {
	for (int idx = 0; str[idx]; idx++) {
		int idx_corpus;
		for (idx_corpus = 0; corpus[idx_corpus]; idx_corpus++) {
			if (str[idx] == corpus[idx_corpus])
				break ;
		}
		if (!corpus[idx_corpus])
			return false;
	}
	return true ;
}

int	main(int ac, char **av) {

	PmergeMe<std::vector<int> >	test(av);
	
	return 1;
}