#include "Bureaucrat.hpp"

int main()
{
    std::cout << "<<< TEST 1: >>>" << std::endl;
    try
    {
        Bureaucrat icha("Icha", 170);
        std::cout << icha.getName() << ", bureaucrat grade " << icha.getGrade() << std::endl; 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "<<< TEST 2: >>>" << std::endl;
    try
    {
        Bureaucrat icha("Icha", -1);
        std::cout << icha.getName() << ", bureaucrat grade " << icha.getGrade() << std::endl; 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "<<< TEST 3: >>>" << std::endl;
    try
    {
        Bureaucrat tapasia("Tapasia", 60);
        std::cout << tapasia.getName() << ", bureaucrat grade " << tapasia.getGrade() << std::endl; 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "<<< TEST 4: >>>" << std::endl;
    try
    {
        Bureaucrat tapasia("Tapasia", 60);
        std::cout << tapasia.getName() << ", bureaucrat grade " << tapasia.getGrade() << std::endl;
        tapasia.incrementGrade();
        std::cout << tapasia.getName() << ", bureaucrat grade " << tapasia.getGrade() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "<<< TEST 5: >>>" << std::endl;
    try
    {
        Bureaucrat icha("Icha", 60);
        std::cout << icha.getName() << ", bureaucrat grade " << icha.getGrade() << std::endl;
        icha.decrementGrade();
        std::cout << icha.getName() << ", bureaucrat grade " << icha.getGrade() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}