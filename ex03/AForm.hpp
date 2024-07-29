#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
	public:

		virtual ~AForm();

		AForm &		operator=( AForm const & rhs );

		const std::string& 	getName() const;
		const bool& 		isSigned() const;
		const int& 			getMinSignGrade() const;
		const int& 			getMinExecGrade() const;
		void				beSigned(Bureaucrat& b);
		virtual void		execute(Bureaucrat const & executor) const = 0;

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

		class NotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class AlreadySignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	protected:
		AForm(std::string name, int minSignGrade, int minExecGrade);
		AForm( AForm const & src );

	private:
		std::string _name;
		bool		_isSigned;
		int			_minSignGrade;
		int			_minExecGrade;

		AForm();
};

std::ostream &operator<<( std::ostream & o, AForm const & i );

#endif /* ************************************************************ FORM_H */