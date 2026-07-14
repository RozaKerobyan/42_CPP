#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat bureaucrat("Icha", 1);
        ShrubberyCreationForm shrubberyForm("home");
        RobotomyRequestForm robotomyForm("Robotomy");
        PresidentialPardonForm pardonForm("Presidential");

        bureaucrat.signForm(shrubberyForm);
        bureaucrat.executeForm(shrubberyForm);
        bureaucrat.signForm(robotomyForm);
        bureaucrat.executeForm(robotomyForm);
        bureaucrat.signForm(pardonForm);
        bureaucrat.executeForm(pardonForm);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
} 