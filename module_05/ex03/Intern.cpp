#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return (*this);
}

Intern::~Intern() {}

AForm *Intern::makeShruberry(std::string target)
{
    return(new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomy(std::string target)
{
    return(new RobotomyRequestForm(target));
}

AForm *Intern::makePresidential(std::string target)
{
    return(new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string formInput, std::string target)
{
    std::string formInputs[3] = {"shrubberry creation", "robotomy request", "presidential pardon"};
    AForm *(Intern::*forms[3])(std::string) = {
        &Intern::makeShruberry,
        &Intern::makeRobotomy,
        &Intern::makePresidential
    };
    for (int i = 0; i < 3; i++)
    {
        if (formInput == formInputs[i])
        {
            std::cout << "Intern creates " << formInput << std::endl;
            return ((this->*forms[i])(target));
        }
    }
    throw FormNotFoundException();
    return (NULL);
}