/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:06:37 by tmouche           #+#    #+#             */
/*   Updated: 2024/10/16 18:20:08 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.class.hpp"

int	main( void ) {
	int			array[5] = {3, 4, 6, 1, 2};
	PmergeMe	test(array, 5);
	
	test.doubleSortMyNumber();
	return 1;
}