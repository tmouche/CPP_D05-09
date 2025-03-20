/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.template.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:14:15 by tmouche           #+#    #+#             */
/*   Updated: 2025/03/20 09:47:39 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TEMPLATE_HPP
# define EASYFIND_TEMPLATE_HPP
# include <algorithm>


template< typename T >
bool	easyFind(T const & container, int const base) {
	typename T::const_iterator	it = std::find(container.begin(), container.end(), base);

	if (*it == base)
		return true;
	return false;
}

#endif
