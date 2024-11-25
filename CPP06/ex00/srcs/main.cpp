/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche < tmouche@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 06:56:34 by thibaud           #+#    #+#             */
/*   Updated: 2024/11/22 16:14:49 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.class.hpp"
#include <iostream>

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Error: Bad input" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}
