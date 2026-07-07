#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool signed_bool;
        const int required_sign;
        const int required_execute;
    public:
        Form();
        Form(const std::string &name, int required_sign, int required_execute);
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();

        std::string getName() const;
        bool getSignedBool() const;
        int getRequiredSign() const;
        int getRequiredExecute() const;

        void beSigned(const Bureaucrat &bureaucrat);

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

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif