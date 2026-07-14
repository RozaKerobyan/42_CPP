#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();

        std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade(); 

        void signForm(AForm &form) const;
        void executeForm(AForm const & form) const;
    
    class GradeTooHighException  : public std::exception
    {
        public:
            const char *what() const throw()
            {
                return("Grade too high!");
            }
    };

    class GradeTooLowException  : public std::exception
    {
        public:
            const char *what() const throw()
            {
                return("Grade too low!");
            }
    };
    
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif