/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 04:29:21 by thibaud           #+#    #+#             */
/*   Updated: 2024/09/18 04:53:51 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_CLASS_HPP
# define SERIALIZER_CLASS_HPP
# include "Data.struct.hpp"
# include <cstdint>

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
