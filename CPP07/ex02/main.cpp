/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:01:29 by thibaud           #+#    #+#             */
/*   Updated: 2024/09/19 08:16:23 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.template.hpp"
#include <iostream>

int	main( void )  {
	Array<int>		intArray(4);
	Array<char>		charArray(4);
	Array<float>	floatArray(4);

	intArray[0] = 1;
	intArray[1] = 2;
	intArray[2] = 3;
	intArray[3] = 0;
	std::cout << "int Array: "<< intArray[0] << "; " << intArray[1] << "; " << intArray[2] << "; " << intArray[3] << std::endl;
	std::cout << "int Array nb of element: " << intArray.size() << std::endl;
	charArray[0] = 'h';
	charArray[1] = 'e';
	charArray[2] = 'l';
	charArray[3] = 'o';
	std::cout << "char Array: "<< charArray[0] << "; " << charArray[1] << "; " << charArray[2] << "; " << charArray[3] << std::endl;
	std::cout << "char Array nb of element: " << charArray.size() << std::endl;
	floatArray[0] = 1.1;
	floatArray[1] = 2.2;
	floatArray[2] = 3.3;
	floatArray[3] = 0.4;
	std::cout << "float Array: "<< floatArray[0] << "; " << floatArray[1] << "; " << floatArray[2] << "; " << floatArray[3] << std::endl;
	std::cout << "float Array nb of element: " << floatArray.size() << std::endl;
	return 0;
}
