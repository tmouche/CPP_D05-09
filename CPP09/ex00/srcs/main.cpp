/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:31:10 by thibaud           #+#    #+#             */
/*   Updated: 2025/02/06 16:47:22 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.class.hpp"
#include "Exception.class.hpp"

int main(int ac, char** av) {
	
	if (ac != 2)
		return 1;
	try {
		BitcoinExchange	test("data.csv");
		test.valorise(av[1]);
	} catch (Exception& e) {
		e.what();
		return 1;
	}
	return 0;
}