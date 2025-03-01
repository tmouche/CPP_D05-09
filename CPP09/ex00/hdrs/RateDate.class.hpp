/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RateDate.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:42:10 by tmouche           #+#    #+#             */
/*   Updated: 2025/02/06 16:44:41 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RATEDATE_CLASS_HPP
# define RATEDATE_CLASS_HPP

class RateDate {
public:
	RateDate( void );
	RateDate(int& year, int& month, int& day);
	RateDate(RateDate const & src);
	~RateDate( void );
	
	RateDate&	operator=(RateDate const & rhs);
	bool		operator<(RateDate const & rhs) const;
	
	int	const	year;
	int	const	month;
	int	const	day;
};

#endif
