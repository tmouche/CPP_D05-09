/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RateDate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:48:49 by tmouche           #+#    #+#             */
/*   Updated: 2025/02/03 20:21:30 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RateDate.class.hpp"

RateDate::RateDate( void ) : year(0), month(0), day(0) {
	return ;
}

RateDate::RateDate(int& inYear, int& inMonth, int& inDay) : year(inYear), month(inMonth), day(inDay) {
	return ;
}

RateDate::RateDate(RateDate const & src) : year(src.year), month(src.month), day(src.day) {
	*this = src;
	return ;
}

RateDate::~RateDate( void ) {
	return ;
}

RateDate&	RateDate::operator=(RateDate const & rhs) {
	if (this != &rhs) {
		(void)rhs;
	}
	return ;
}

bool	RateDate::operator<(RateDate const & rhs) {
	if (this->year < rhs.year)
		return true;
	if (this->month < rhs.month)
		return true;
	if (this->day < rhs.day)
		return true;
	return false;
}
