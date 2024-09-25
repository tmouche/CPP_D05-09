/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.template.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:07:59 by tmouche           #+#    #+#             */
/*   Updated: 2024/09/25 13:42:53 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TEMPLATE_HPP
# define MUTANTSTACK_TEMPLATE_HPP

template< typename T >
class MutantStack {
public :
	MutantStack( void );
	~MutantStack( void );
	MutantStack(MutantStack const & src);
	
	MutantStack&	operator=(MutantStack const & rhs);

private :
	
};

#endif