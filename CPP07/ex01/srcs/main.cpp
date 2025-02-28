/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:34:06 by thibaud           #+#    #+#             */
/*   Updated: 2024/09/18 12:46:36 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.template.hpp"
#include <iostream>

template< typename Type >
void	printDate(Type& Data) {
	std::cout << Data << std::endl;
	return ;
}

template< typename Type >
void	printDate(Type const & Data) {
	std::cout << Data << std::endl;
	return ;
}

int	main( void ) {
	int		intArray[3] = {2, 3, 4};
	float	floatArray[3] = {3.432, 4.78, 5.43};

	std::cout << "Call iter for Type = int" << std::endl;
	iter<int>(intArray, 3, printDate<int>);
	std::cout << "Call iter for Type = float" << std::endl;
	iter<float>(floatArray, 3, printDate<float>);
	return 0;
}