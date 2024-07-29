#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;
class Intern
{

	public:

		Intern();
		Intern( Intern const & src );
		~Intern();

		Intern&	operator=( Intern const & rhs );
		AForm	*makeForm(std::string formName, std::string formTarget);

		class FormNotFoundException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &			operator<<( std::ostream & o, Intern const & i );

#endif /* ********************************************************** INTERN_H */