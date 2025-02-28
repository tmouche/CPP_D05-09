/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.template.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:18:55 by thibaud           #+#    #+#             */
/*   Updated: 2024/09/18 10:24:51 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_TEMPLATE_HPP
# define WHATEVER_TEMPLATE_HPP

template< typename Type >
void	swap(Type x, Type y) {
	Type	temp;
	temp = x;
	x = y;
	y = temp;
	return ;
}

template< typename Type >
Type	min(Type const x, Type const y) {
	return ((y<=x) ? (y) : (x));
}

template< typename Type >
Type	max(Type const x, Type const y) {
	return ((y>=x) ? (y) : (x));
}

#endif
