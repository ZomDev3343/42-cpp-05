#include "AForm.hpp"

AForm::AForm()
{
}

AForm::AForm(std::string name, int minSignGrade, int minExecGrade)
{
	this->_name = name;
	this->_minSignGrade = minSignGrade;
	if (this->_minSignGrade < 1)
		throw AForm::GradeTooHighException(this->_minSignGrade);
	else if (this->_minSignGrade > 150)
		throw AForm::GradeTooLowException(this->_minSignGrade);
	this->_minExecGrade = minExecGrade;
	if (this->_minExecGrade < 1)
		throw AForm::GradeTooHighException(this->_minExecGrade);
	else if (this->_minExecGrade > 150)
		throw AForm::GradeTooLowException(this->_minExecGrade);
	this->_isSigned = false;
}

AForm::AForm(const AForm &src)
{
	*this = src;
}

AForm::~AForm()
{
}

AForm &AForm::operator=( AForm const & rhs )
{
	this->_name = rhs._name;
	this->_isSigned = rhs._isSigned;
	this->_minSignGrade = rhs._minSignGrade;
	this->_minExecGrade = rhs._minExecGrade;
	return *this;
}

const std::string &AForm::getName() const
{
	return this->_name;
}

const bool& AForm::isSigned() const
{
	return this->_isSigned;
}

const int &AForm::getMinSignGrade() const
{
	return this->_minSignGrade;
}

const int &AForm::getMinExecGrade() const
{
	return this->_minExecGrade;
}

void AForm::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > this->getMinSignGrade())
		throw AForm::GradeTooLowException(b.getGrade());
	if (this->_isSigned)
		throw AForm::AlreadySignedException();
	this->_isSigned = true;
}

std::ostream &operator<<( std::ostream & o, AForm const & i )
{
	o << "AForm Name : " << i.getName() << std::endl << "Is AForm signed? : " << i.isSigned()
		<< std::endl << "Minimum grade to sign : " << i.getMinSignGrade() << std::endl
		<< "Minimum grade to execute it : " << i.getMinExecGrade() << std::endl;
	return o;
}

AForm::GradeTooHighException::GradeTooHighException(int grade)
{
	this->grade = grade;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Error: AForm grade too high !");
}

AForm::GradeTooLowException::GradeTooLowException(int grade)
{
	this->grade = grade;
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Error: Form grade too low !");
}

const char *AForm::NotSignedException::what() const throw()
{
	return ("Error: Form is not signed !");
}

const char *AForm::AlreadySignedException::what() const throw()
{
	return ("Error: Form is already signed !");
}
