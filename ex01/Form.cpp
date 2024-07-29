#include "Form.hpp"

Form::Form()
{
}

Form::Form(std::string name, int minSignGrade, int minExecGrade)
{
	this->_name = name;
	this->_minSignGrade = minSignGrade;
	if (this->_minSignGrade < 1)
		throw Form::GradeTooHighException(this->_minSignGrade);
	else if (this->_minSignGrade > 150)
		throw Form::GradeTooLowException(this->_minSignGrade);
	this->_minExecGrade = minExecGrade;
	if (this->_minExecGrade < 1)
		throw Form::GradeTooHighException(this->_minExecGrade);
	else if (this->_minExecGrade > 150)
		throw Form::GradeTooLowException(this->_minExecGrade);
	this->_isSigned = false;
}

Form::Form(const Form &src)
{
	*this = src;
}

Form::~Form()
{
}

Form &Form::operator=( Form const & rhs )
{
	this->_name = rhs._name;
	this->_isSigned = rhs._isSigned;
	this->_minSignGrade = rhs._minSignGrade;
	this->_minExecGrade = rhs._minExecGrade;
	return *this;
}

const std::string &Form::getName() const
{
	return this->_name;
}

const bool Form::isSigned() const
{
	return this->_isSigned;
}

const int &Form::getMinSignGrade() const
{
	return this->_minSignGrade;
}

const int &Form::getMinExecGrade() const
{
	return this->_minExecGrade;
}

void Form::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > this->getMinSignGrade())
		throw Form::GradeTooLowException(b.getGrade());
	if (this->_isSigned)
		throw Form::AlreadySignedException();
	this->_isSigned = true;
}

std::ostream &operator<<( std::ostream & o, Form const & i )
{
	o << "Form Name : " << i.getName() << std::endl << "Is form signed? : " << i.isSigned()
		<< std::endl << "Minimum grade to sign : " << i.getMinSignGrade() << std::endl
		<< "Minimum grade to execute it : " << i.getMinExecGrade() << std::endl;
	return o;
}

Form::GradeTooHighException::GradeTooHighException(int grade)
{
	this->grade = grade;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Error: Form grade too high !");
}

Form::GradeTooLowException::GradeTooLowException(int grade)
{
	this->grade = grade;
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Error: Form grade too low !");
}

const char *Form::AlreadySignedException::what() const throw()
{
	return ("Error: Form is already signed !");
}
