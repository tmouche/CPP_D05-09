/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:32:40 by tmouche           #+#    #+#             */
/*   Updated: 2024/10/10 20:34:43 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.class.hpp"
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <limits>

int const	BitcoinExchange::_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int const	BitcoinExchange::_monthLeap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

BitcoinExchange::BitcoinExchange( void ){
	return ;
}

BitcoinExchange::~BitcoinExchange( void ) {
	return ;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src) {
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
		else if (idx < seedSize && seed[idx] != data[idx])
			 	return false;
	}
	return true;
}

int	BitcoinExchange::convertDate(std::string date) const {
	double		res;
	int			temp;
	double		fix;
	int const *	month;

	if (!checkString("xxxx-xx-xx", date, "0123456789"))
		throw inputException();
	res = std::atoi(date.c_str());
	date.erase(0, date.find('-') + 1);
	temp = std::atoi(date.c_str());
	if (temp < 1 || temp > 12)
		throw inputException();
	if ((!std::modf(res / 4, &fix) && std::modf(res  / 100, &fix)) 
		|| !std::modf(res / 400, &fix))
		month = this->_monthLeap;
	else
		month = this->_month;
	res *= 1000;
	for (int idx = 0; idx < temp - 1; idx++) {
		res += month[idx];
	}
	date.erase(0, date.find('-') + 1);
	res += std::atoi(date.c_str());
	return static_cast<int>(res);
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
		try {this->_dataBaseDate.push_back(convertDate(dataStr));}
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
	int	idx;

	for (idx = 0; dateConverted > this->_dataBaseDate[idx]; idx++);
	if (dateConverted > this->_dataBaseDate[idx]);
		--idx;
	return idx;
}

void	BitcoinExchange::lineValue(std::string line) {
	std::string	temp;
	float		amount;
	int			date;

	if (!checkString("xxxx-xx-xx | x", line, "0123456789-")) {
		std::cout << "Error : bad input => " << line;
	}
	temp = line;
	try {date = convertDate(line);}
	catch (inputException& e) {
		e.what(temp);
		return ;
	}
	line.erase(0, line.find('|') + 1);
	amount = std::atof(line.c_str());
	if (amount < 0)
		throw NegativeValueException();
	else if (amount >= __INT_MAX__)
		throw TooLargeValueException();
	temp.assign(temp, 0, 10);
	std::cout << temp << " => " << amount << " = " << amount * this->_dataBaseRate[dateToIdx(date)] << std::endl;
	return ;
}

void	BitcoinExchange::valueMyWallet(std::string inFile) {
	std::string	dataStr;
	
	std::ifstream	ifs(inFile.c_str());
	if (!ifs)
		throw FileException();
	dataStr.clear();
	std::getline(ifs, dataStr, '\n');
	while (dataStr[0]) {
		if (dataStr[0] >= '0' && dataStr[0] <= '9') {
			try {lineValue(dataStr);}
			catch (NegativeValueException& e) {e.what();}
			catch (TooLargeValueException& e) {e.what();}
		}
		std::getline(ifs, dataStr, '\n');
	}
	return ;
}
