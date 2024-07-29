#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat good("Michael", 5), bad("John", 148);
	Form f1("F1", 25, 20), f2("F2", 149, 149), f3("F3", 50, 50);
	try
	{
		good.signForm(f1);
		bad.signForm(f2);
		bad.signForm(f3);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		good.signForm(f2);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		Form f4("F4", 0, 50);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		Form f4("F4", 50, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Form f4("F4", 250, 50);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Form f4("F4", 50, 250);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}