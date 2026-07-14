#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class   Intern
{
    public:
        Intern();
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        ~Intern();

        AForm *makeForm(std::string formInput, std::string target);
        AForm *makeShruberry(std::string target);
        AForm *makeRobotomy(std::string target);
        AForm *makePresidential(std::string target);

        class FormNotFoundException : public std::exception
        {
        public:
            const char* what() const throw()
            {
                return "Intern can't create form";
            }
        };
};

#endif