/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 03:10:06 by thibaud           #+#    #+#             */
/*   Updated: 2024/11/25 17:24:37 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_CLASS_HPP
# define BUREAUCRAT_CLASS_HPP
# include <string>
# include <iostream>

class AForm;

class Bureaucrat {
public :
	Bureaucrat(std::string name, int grade);
	~Bureaucrat( void );
	Bureaucrat(Bureaucrat const & src);

	Bureaucrat&	operator=(Bureaucrat const & rhs);

	class GradeTooHighException {
	public :	
		virtual void what() const throw() {}
	};

	class GradeTooLowException {
	public :	
		virtual void what() const throw() {}
	};

	std::string	getName( void ) const;
	int			getGrade( void ) const;

	void		incrementGrade( void );
	void		decrementGrade( void );
	void		signForm(AForm& form);
	void		executeForm(AForm const & form);

private :
	Bureaucrat( void );

	std::string	_name;
	int			_grade;

};

std::ostream&	operator<<(std::ostream& out, Bureaucrat const & rhs);

#endif
