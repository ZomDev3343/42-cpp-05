/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:10:42 by tohma             #+#    #+#             */
/*   Updated: 2024/07/29 23:23:32 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Intern.hpp"

int main()
{
	Bureaucrat good("Michael", 5), bad("John", 145), ok("Billy", 64);
	Intern marc;
	std::srand(time(NULL));

	AForm * form = marc.makeForm("sHrUBbery", "Bob");
	if (form)
		std::cout << *form << std::endl;
	delete form;

	AForm * form1 = marc.makeForm("roBotOmY request", "Lucas");
	if (form1)
		std::cout << *form1 << std::endl;
	delete form1;

	AForm * form2 = marc.makeForm("presidental", "Alan");
	if (form2)
		std::cout << *form2 << std::endl;
	delete form2;

	AForm * form3 = marc.makeForm("presidentialpardonform", "Pipin");
	if (form3)
		std::cout << *form3 << std::endl;
	delete form3;
	
	AForm * form4 = marc.makeForm("sfeHrUBbery", "Godrick");
	if (form4)
		std::cout << *form4 << std::endl;
	delete form4;
	return 0;
}