/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:53:42 by tohma             #+#    #+#             */
/*   Updated: 2024/07/29 20:33:57 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	//std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	this->_name = name;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException(grade);
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException(grade);
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	*this = src;
}

Bureaucrat::~Bureaucrat()
{
	//std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	this->_name = rhs._name;
	this->_grade = rhs._grade;
	return *this;
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException(this->_grade);
	this->_grade--;
	std::cout << "Incrementing " << this->_name << "'s grade" << std::endl;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException(this->_grade);
	this->_grade++;
	std::cout << "Decrementing " << this->_name << "'s grade" << std::endl;
}

const std::string &Bureaucrat::getName() const
{
	return this->_name;
}

const int &Bureaucrat::getGrade() const
{
	return this->_grade;
}

std::ostream &operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade();
	return o;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(int grade)
{
	this->grade = grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Error: Incorrect grade, too high !";
}

Bureaucrat::GradeTooLowException::GradeTooLowException(int grade)
{
	this->grade = grade;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Error: Incorrect grade, too low !";	
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because "
		<< e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn't execute " << form.getName()
		<< " because " << e.what() << std::endl;
	}
	
}
