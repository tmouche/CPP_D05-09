/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche < tmouche@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 04:29:21 by thibaud           #+#    #+#             */
/*   Updated: 2024/11/22 16:40:54 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_CLASS_HPP
# define SERIALIZER_CLASS_HPP
# include "Data.struct.hpp"
# include <stdint.h>

class Serializer {
public :
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);

private :
	Serializer( void );
	~Serializer( void );
	Serializer(Serializer const & src);
	
	Serializer&	operator=(Serializer const & rhs);
};

#endif
