#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat good("GoodOne", 149);
	Bureaucrat bad("BadOne", 2);
	try
	{
		std::cout << good << std::endl;
		std::cout << bad << std::endl;
		bad.incrementGrade();
		std::cout << bad << std::endl;
		good.decrementGrade();
		std::cout << good << std::endl;
		bad.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	
	try
	{
		good.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}