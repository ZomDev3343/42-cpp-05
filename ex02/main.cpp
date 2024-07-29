/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:10:42 by tohma             #+#    #+#             */
/*   Updated: 2024/07/29 22:45:46 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat good("Michael", 5), bad("John", 145), ok("Billy", 64);
	ShrubberyCreationForm sbf("Bob");
	RobotomyRequestForm rbf("Alex");
	PresidentialPardonForm ppf("Lara");

	std::srand(time(NULL));

	try
	{
		bad.signForm(sbf);
		good.signForm(sbf);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		bad.signForm(rbf);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		ok.signForm(rbf);
		ok.signForm(ppf);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		ok.signForm(rbf);
		ok.signForm(ppf);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		good.signForm(ppf);
		bad.executeForm(sbf);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		good.signForm(ppf);
		good.executeForm(sbf);
		good.executeForm(rbf);
		good.executeForm(rbf);
		good.executeForm(rbf);
		good.executeForm(rbf);
		good.executeForm(ppf);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}