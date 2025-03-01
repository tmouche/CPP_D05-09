/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.template.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche < tmouche@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:14:15 by tmouche           #+#    #+#             */
/*   Updated: 2024/11/22 17:05:44 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TEMPLATE_HPP
# define EASYFIND_TEMPLATE_HPP

template< typename T >
bool	easyFind(T const & container, int const base) {
	typename T::const_iterator	it;
	
	for (it = container.begin(); it != container.end(); it++) {
		if (*it == base)
		 	return true;
	}
	return false;
}

#endif
