/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RateDate.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:42:10 by tmouche           #+#    #+#             */
/*   Updated: 2025/05/15 14:25:01 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RATEDATE_CLASS_HPP
# define RATEDATE_CLASS_HPP

class RateDate {
public:
	RateDate( void );
	RateDate(int year, int month, int day, float price);
	RateDate(RateDate const & src);
	~RateDate( void );
	
	RateDate&	operator=(RateDate const & rhs);
	bool		operator<(RateDate const & rhs) const;
	bool		operator==(RateDate const & rhs) const;

	struct	Comparator {
		bool	operator()(RateDate const * a, RateDate const * b);
	};
	
	int	const	year;
	int	const	month;
	int	const	day;

	float const	price;
};

#endif
