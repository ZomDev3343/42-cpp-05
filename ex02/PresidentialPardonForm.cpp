#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm::AForm("PresidentialPardonForm", 25, 5)
{
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src ) : AForm::AForm(src)
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm &				PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	AForm::operator=(rhs);
	this->_target = rhs._target;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, PresidentialPardonForm const & i )
{
	operator<<(o, (const AForm &) i);
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getMinExecGrade())
		throw AForm::GradeTooLowException(executor.getGrade());
	if (!this->isSigned())
		throw AForm::NotSignedException();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */