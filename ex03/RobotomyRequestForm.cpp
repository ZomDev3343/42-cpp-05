#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm::AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ) : AForm::AForm(src)
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	AForm::operator=(rhs);
	this->_target = rhs._target;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i )
{
	operator<<(o, (const AForm &) i);
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
				
void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getMinExecGrade())
		throw AForm::GradeTooLowException(executor.getGrade());
	if (!this->isSigned())
		throw AForm::NotSignedException();
	int rand = std::rand() % 2;
	std::cout << "Drrrrrr!" << std::endl;
	if (rand)
		std::cout << this->_target << " has been robotomized" << std::endl;
	else
		std::cout << this->_target << " has not been robotomized" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */