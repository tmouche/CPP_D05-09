/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:15:54 by thibaud           #+#    #+#             */
/*   Updated: 2024/09/11 18:35:55 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_CLASS_HPP
# define INTERN_CLASS_HPP
# include <string>
# include "AForm.class.hpp"

class Intern {
public :
	Intern( void );
	~Intern( void );
	Intern(Intern const & src);

	Intern&	operator=(Intern const & rhs);
	
	AForm*	makeForm(std::string nameForm, std::string target);

};

#endif
