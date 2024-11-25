/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.class.hpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 03:47:33 by thibaud           #+#    #+#             */
/*   Updated: 2024/09/11 05:14:27 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_CLASS_HPP
# define SHRUBBERYCREATIONFORM_CLASS_HPP
# include "AForm.class.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
public :
	~ShrubberyCreationForm( void );
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const & src);
	
	ShrubberyCreationForm&	operator=(ShrubberyCreationForm const & rhs);

	virtual void	execute(Bureaucrat const & executor) const;

private :
	ShrubberyCreationForm( void );
	std::string	_target;

};
	
#endif