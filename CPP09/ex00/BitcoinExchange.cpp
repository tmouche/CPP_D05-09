/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:32:40 by tmouche           #+#    #+#             */
/*   Updated: 2024/10/09 15:03:31 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.class.hpp"
#include <fstream>
#include <cstdlib>

int const	BitcoinExchange::_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int const	BitcoinExchange::_monthLeap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

BitcoinExchange::BitcoinExchange(std::string seed, int offset) : _seed(BitcoinExchange::convertDate(seed)), _offset(offset) {
	return ;
}

BitcoinExchange::BitcoinExchange( void ) : _seed(0), _offset(0) {
	return ;
}

BitcoinExchange::~BitcoinExchange( void ) {
	return ;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src) : _seed(src._seed), _offset(src._offset) {
	return ;
}

BitcoinExchange&	BitcoinExchange::operator=(BitcoinExchange const & rhs) {
	return *this;
}

bool	checkString(std::string const seed, std::string const data, std::string const corpus) {
	int const	seedSize = seed.size();
	int			idx = 0;

	if (seed.empty() || data.empty() || corpus.empty())
		return false;
	for (int idx = 0; data[idx]; idx++) {
		if (idx < seedSize) {
			if (seed[idx] == 'x') {
				for (int idxCorpus = 0; true; idxCorpus++) {
					if (data[idx] == corpus[idxCorpus])
						break ;
					if (!corpus[idxCorpus + 1])
						return false;
				}
			}
			else if (seed[idx] != data[idx])
			 	return false;
		}
	}
	return true;
}

int	BitcoinExchange::convertDate(std::string date) {
	int		size = date.size();
	size_t	pos = 0;
	int		temp = 0;
	int		res = 0;

	if (size != 10 || !checkString("xxxx-xx-xx", date, "0123456789"))
		throw BitcoinExchange::FileException();
	res = std::atoi(date.c_str());
	pos = date.find('-');
	date.erase(0, ++pos);
	res *= 1000;
	temp = std::atoi(date.c_str());
	if (temp < 0 || temp > 12)
		throw BitcoinExchange::FileException();
	
		
}