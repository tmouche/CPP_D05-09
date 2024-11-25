/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.template.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:17:28 by thibaud           #+#    #+#             */
/*   Updated: 2024/09/18 13:02:52 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_TEMPLATE_HPP
# define ITER_TEMPLATE_HPP

template< typename Type >
void	iter(Type* array, int length, void (*functionPtr)(Type)) {
	for (int idx = 0; idx < length; idx++)
		functionPtr(array[idx]);
	return ;
}

#endif