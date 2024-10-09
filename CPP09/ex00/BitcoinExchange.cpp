/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:32:40 by tmouche           #+#    #+#             */
/*   Updated: 2024/10/09 21:12:22 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.class.hpp"
#include <fstream>
#include <cstdlib>

int const	BitcoinExchange::_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int const	BitcoinExchange::_monthLeap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

BitcoinExchange::BitcoinExchange(std::string seed, int offset) : _seed(convertDate(seed)), _offset(offset) {
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

bool	BitcoinExchange::checkString(std::string const seed, std::string const data, std::string const corpus) const {
	int const	seedSize = seed.size();
	int			idx = 0;

	if (seed.empty() || data.empty() || corpus.empty())
		return false;
	for (int idx = 0; data[idx]; idx++) {
		if (idx < seedSize && seed[idx] == 'x') {
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
	return true;
}

int	BitcoinExchange::convertDate(std::string date) const {
	int			res;
	int			temp;
	int const *	month;

	if (!checkString("xxxx-xx-xx", date, "0123456789"))
		throw inputException();
	res = std::atoi(date.c_str());
	date.erase(0, date.find('-') + 1);
	temp = std::atoi(date.c_str());
	if (temp < 1 || temp > 12)
		throw inputException();
	if ((res / 4 % 10 == 0 && res / 100 % 10 != 0) || res / 400 % 10 == 0)
		month = this->_monthLeap;
	else
		month = this->_month;
	res *= 1000;
	for (int idx = 0; idx < temp - 1; idx++) {
		res += month[idx];
	}
	date.erase(0, date.find('-') + 1);
	temp = std::atoi(date.c_str());
	res += temp;
	return res;
}

void	BitcoinExchange::dataLoader( void ) {
	std::string	dataStr;
	std::string	temp;

	std::ifstream	ifs("data.csv");
	if (!ifs)
		throw FileException();
	dataStr.clear();
	std::getline(ifs, dataStr, '\n');
	std::getline(ifs, dataStr, '\n');
	while (dataStr[0]) {
		if (!checkString("xxxx-xx-xx,x", dataStr, "0123456789"))
			throw inputException();
		temp = dataStr; 
		try {convertDate(dataStr);}
		catch (inputException& e) {
			e.what(temp);
			throw Exception();
		}
		dataStr.erase(0, dataStr.find(',') + 1);
		this->_dataBaseRate.push_back(std::atof(dataStr.c_str()));
		std::getline(ifs, dataStr, '\n');
	}
	ifs.close();
	return ;
}

int		BitcoinExchange::dateToIdx(int const dateConverted) const {
	return ;
}

void	BitcoinExchange::valueMyWallet(std::string inFile) {
	std::string	dataStr;
	std::string	temp;
	int			date;
	
	std::ifstream	ifs(inFile.c_str());
	if (!ifs)
		throw FileException();
	dataStr.clear();
	std::getline(ifs, dataStr, '\n');
	while (dataStr[0]) {
		if (dataStr[0] >= '0' && dataStr[0] <= '9') {
			if (!checkString("xxxx-xx-xx | x", dataStr, "0123456789-")) {
				std::cout << "Error : bad input => " << dataStr;
			}
			temp = dataStr;
			try {date = convertDate(dataStr);}
			catch (inputException& e) {e.what(temp);}
			this->_dataBaseRate.push_back(std::atof(dataStr.c_str()));
		}
		std::getline(ifs, dataStr, '\n');
	}
	return ;
}
