/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:31:29 by thibaud           #+#    #+#             */
/*   Updated: 2024/09/09 22:11:34 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_CLASS_HPP
# define AFORM_CLASS_HPP
# include <string>

class Bureaucrat;

class AForm {
public :
	AForm( void );
	~AForm( void );
	AForm(std::string name, int gradeSign, int gradeExecute);
	AForm(AForm const & src);
	
	AForm&	operator=(AForm const & rhs);

	class GradeTooHighException {
	public :
		virtual const void	what() const throw() {};
	};

	class GradeTooLowException {
	public :
		virtual const void	what() const throw() {};
	};

	class FormNotSigned {
	public :
		virtual const void	what() const throw() {};
	};
	
	std::string	getName( void ) const;
	bool		getSigned( void ) const;
	int			getGradeSign( void ) const;
	int			getGradeExecute( void ) const;

	virtual void	beSigned(Bureaucrat const & src);
	virtual void	execute(Bureaucrat const & executor) const = 0;

private :
	std::string	const	_name;
	bool				_signed;
	int const			_gradeSign;
	int const			_gradeExecute;

};

std::ostream&	operator<<(std::ostream& out, AForm const & rhs);

#endif
