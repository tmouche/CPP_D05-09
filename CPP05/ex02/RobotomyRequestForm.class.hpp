/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.class.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 04:06:54 by thibaud           #+#    #+#             */
/*   Updated: 2024/09/11 04:30:02 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFARM_CLASS_HPP
# define ROBOTOMYREQUESTFARM_CLASS_HPP
# include "AForm.class.hpp"

class RobotomyRequestFarm : public AForm {
public :
	~RobotomyRequestFarm( void );
	RobotomyRequestFarm(std::string target);
	RobotomyRequestFarm(RobotomyRequestFarm const & src);

	RobotomyRequestFarm&	operator=(RobotomyRequestFarm const & rhs);

	virtual void	execute(Bureaucrat const & executor) const;

private :
	RobotomyRequestFarm( void );
	std::string	_target;

};

#endif