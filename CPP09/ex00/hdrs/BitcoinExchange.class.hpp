/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:43:36 by tmouche           #+#    #+#             */
/*   Updated: 2025/02/04 17:08:31 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_CLASS_HPP
# define BITCOINEXCHANGE_CLASS_HPP
# include <map>
# include <string>
# include "RateDate.class.hpp"

class BitcoinExchange {
public:
	BitcoinExchange( void );
	~BitcoinExchange( void );
	BitcoinExchange(std::string const & dbFile);
	BitcoinExchange(BitcoinExchange const & src);
	
	BitcoinExchange&	operator=(BitcoinExchange const & rhs);

	void	valorise(std::string const & walletFile);
	
private:
	void	chargeDb( void );

	std::map<RateDate&, float>	_dataBase;

	std::string const	_dbFile;
	
	bool	checkPart(std::string const & line, std::string const & exemple);
	void	checkDate(RateDate& date);

	static unsigned short	_month[12];
	static unsigned short	_monthLeap[12];
};

#endif
