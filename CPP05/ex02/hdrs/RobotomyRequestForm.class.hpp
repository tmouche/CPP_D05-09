/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.class.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 04:06:54 by thibaud           #+#    #+#             */
/*   Updated: 2024/09/11 18:39:59 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RobotomyRequestForm_CLASS_HPP
# define RobotomyRequestForm_CLASS_HPP
# include "AForm.class.hpp"

class RobotomyRequestForm : public AForm {
public :
	~RobotomyRequestForm( void );
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const & src);

	RobotomyRequestForm&	operator=(RobotomyRequestForm const & rhs);

	virtual void	execute(Bureaucrat const & executor) const;

private :
	RobotomyRequestForm( void );
	std::string	_target;

};

#endif