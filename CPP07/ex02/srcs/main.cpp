/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:01:29 by thibaud           #+#    #+#             */
/*   Updated: 2025/02/20 16:37:57 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.template.hpp"
#include <iostream>
#include <cstdlib>
#define MAX_VAL 750

int main(int, char**)
{
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

	std::cout << "--- GIVEN MAIN TESTES ---" << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}