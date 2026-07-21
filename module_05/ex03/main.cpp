#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    try
    {
        Intern someRandomIntern;
        AForm* robotomy;
        AForm* shrubbbery;
        AForm* presidential;
        AForm* errorForm;
        robotomy = someRandomIntern.makeForm("robotomy request", "Icha");
        delete robotomy;
        shrubbbery = someRandomIntern.makeForm("shrubberry creation", "Tapasia");
        delete shrubbbery;
        presidential = someRandomIntern.makeForm("presidential pardon", "Takur Sahab");
        delete presidential;
        errorForm = someRandomIntern.makeForm("Nani", "error");
        delete errorForm;
    }
    catch(const std::exception& e)
    {
        std::cerr << "EXCEPTION: " << e.what() << '\n';
    }
} 