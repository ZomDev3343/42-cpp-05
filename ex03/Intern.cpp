# include "Intern.hpp"


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
}

Intern::Intern( const Intern & src )
{
	(void)src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	(void) rhs;
	return *this;
}

AForm *Intern::makeForm(std::string formName, std::string formTarget)
{
	(void) formTarget;
	std::string formNameLower;
	AForm*	form = NULL;

	for (std::string::iterator it = formName.begin(); it != formName.end(); ++it)
		formNameLower += tolower(*it);
	try
	{
		if (formNameLower.find("shrubbery") != formNameLower.npos)
			form =  new ShrubberyCreationForm(formTarget);
		if (formNameLower.find("robotomy") != formNameLower.npos)
			form = new RobotomyRequestForm(formTarget);
		if (formNameLower.find("presidential") != formNameLower.npos)
			form = new PresidentialPardonForm(formTarget);
		if (!form)
			throw FormNotFoundException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	if (form)
		std::cout << "Intern creates " << form->getName() << std::endl;
	return form;
}

std::ostream &			operator<<( std::ostream & o, Intern const & i )
{
	(void)i;
	o << "Intern";
	return o;
}

const char *Intern::FormNotFoundException::what() const throw()
{
	return "Error: Incorrect form name !";	
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */