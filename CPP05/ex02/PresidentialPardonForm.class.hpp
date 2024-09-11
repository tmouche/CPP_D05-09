/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.class.hpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 04:17:48 by thibaud           #+#    #+#             */
/*   Updated: 2024/09/11 04:29:57 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_CLASS_HPP
# define PRESIDENTIALPARDONFORM_CLASS_HPP
# include "AForm.class.hpp"

class PresidentialPardonForm : public AForm {
public :
	~PresidentialPardonForm( void );
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const & src);

	PresidentialPardonForm&	operator=(PresidentialPardonForm const & rhs);

	virtual void	execute(Bureaucrat const & executor) const;

private :
	PresidentialPardonForm( void );
	std::string	_target;
};

#endif
