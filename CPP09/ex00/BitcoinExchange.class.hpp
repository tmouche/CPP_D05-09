/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:17:29 by tmouche           #+#    #+#             */
/*   Updated: 2024/10/09 13:42:13 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_CLASS_HPP
# define BITCOINEXCHANGE_CLASS_HPP
# include <vector>
# include <string>
#include <iostream>

class BitcoinExchange {
public : 
	BitcoinExchange(std::string seed, int offset);
	~BitcoinExchange( void );
	BitcoinExchange(BitcoinExchange const & src);

	BitcoinExchange&	operator=(BitcoinExchange const & rhs);

	void	dataBaseLoader(std::string DbName);
	void	inputLoader(std::string DbName);

	class	FileException {
	public :
		virtual const void	what() const throw() {}
	};

private :
	BitcoinExchange( void );
	int	convertDate(std::string date);
	
	std::vector<int>_dataBaseDate;
	std::vector<float>_dataBaseRate;
	std::vector<int>_inputDate;
	std::vector<float>_inputValue;

	int	const _seed;
	int	const _offset;
	static int const	_month[12];/* = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};*/
	static int const	_monthLeap[12];/* = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};*/
};

#endif