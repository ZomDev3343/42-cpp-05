/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:58:04 by tohma             #+#    #+#             */
/*   Updated: 2024/07/29 19:30:45 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class AForm;
class Bureaucrat
{
	public:

		Bureaucrat(std::string name, int grade);
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();

		Bureaucrat &		operator=( Bureaucrat const & rhs );

		const std::string	&getName() const;
		const int			&getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(AForm& form);
		void				executeForm(AForm const & form);

		class GradeTooHighException : public std::exception
		{
			private:
				int	grade;
			public:
				GradeTooHighException(int grade);
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			private:
				int	grade;
			public:
				GradeTooLowException(int grade);
				virtual const char *what() const throw();
		};

	private:
		std::string _name;
		int			_grade;

		Bureaucrat();
};

std::ostream &operator<<( std::ostream & o, Bureaucrat const & i );

#endif