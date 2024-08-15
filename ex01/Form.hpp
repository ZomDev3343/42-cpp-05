#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
	public:

		Form(std::string name, int minSignGrade, int minExecGrade);
		Form( Form const & src );
		~Form();

		Form &		operator=( Form const & rhs );

		const std::string& 	getName() const;
		bool 				isSigned() const;
		const int& 			getMinSignGrade() const;
		const int& 			getMinExecGrade() const;
		void				beSigned(Bureaucrat& b);

		class GradeTooHighException : public std::exception
		{
			private:
				int grade;
			public:
				GradeTooHighException(int grade);
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			private:
				int grade;
			public:
				GradeTooLowException(int grade);
				virtual const char *what() const throw();
		};

		class AlreadySignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		std::string _name;
		bool		_isSigned;
		int			_minSignGrade;
		int			_minExecGrade;

		Form();
};

std::ostream &operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */
