#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

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