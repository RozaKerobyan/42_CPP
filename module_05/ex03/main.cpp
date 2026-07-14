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
        shrubbbery = someRandomIntern.makeForm("shrubberry creation", "Tapasia");
        presidential = someRandomIntern.makeForm("presidential pardon", "Takur Sahab");
        errorForm = someRandomIntern.makeForm("Nani", "error");

        delete robotomy;
        delete shrubbbery;
        delete presidential;
        delete errorForm;
    }
    catch(const std::exception& e)
    {
        std::cerr << "EXCEPTION: " << e.what() << '\n';
    }
} 