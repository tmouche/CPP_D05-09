/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RateDate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:48:49 by tmouche           #+#    #+#             */
/*   Updated: 2025/05/15 14:52:38 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RateDate.class.hpp"

RateDate::RateDate( void ) : year(0), month(0), day(0), price(0.0) {
	return ;
}

RateDate::RateDate(int y, int m, int d, float p) : year(y), month(m), day(d), price(p) {
	return ;
}

RateDate::RateDate(RateDate const & src) : year(src.year), month(src.month), day(src.day), price(src.price) {
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
	return *this;
}

bool	RateDate::operator<(RateDate const & rhs) const {
	if (this->year <= rhs.year && this->month <= rhs.month && this->day < rhs.day)
		return true;
	return false;
}

bool	RateDate::operator==(RateDate const & rhs) const {
	if (this->year == rhs.year && this->month == rhs.month && this->day == rhs.day)
		return true;
	return false;
}

#include <iostream>

bool		RateDate::Comparator::operator()(RateDate const * a, RateDate const * b) {
	if (a->year != b->year)
		return a->year < b->year;
	if (a->month != b->month)
		return a->month < b->month;
	return a->day < b->day;
}
