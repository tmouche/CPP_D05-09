/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:43:36 by tmouche           #+#    #+#             */
/*   Updated: 2025/05/22 10:29:27 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_CLASS_HPP
# define BITCOINEXCHANGE_CLASS_HPP
# include "RateDate.class.hpp"
# include <sstream>
# include <string>
# include <set>

class BitcoinExchange {
public:
	BitcoinExchange( void );
	~BitcoinExchange( void );
	BitcoinExchange(std::string const & dbFile);
	BitcoinExchange(BitcoinExchange const & src);
	
	BitcoinExchange&	operator=(BitcoinExchange const & rhs);

	void	chargeDb( void );
	void	valorise(std::string const & walletFile);
	
private:
	std::string	dumpFile(std::string const & name);

	RateDate*	createDate(std::string const & date, float const price);
	void 		displayLine(std::string const & date, float amount, float price);
	
	bool	checkPrice(std::string & rate);
	bool	checkDate(std::string const & date);
	bool	checkDate(RateDate const * date);
	
	float	getPrice(RateDate &date);
	bool	isAlreadyPriced(RateDate &date);

	std::set<RateDate*, RateDate::Comparator>	_dataBase;
	std::string const							_dbFile;

	static unsigned short const	_month[12];
	static unsigned short const	_monthLeap[12];
};

#endif
