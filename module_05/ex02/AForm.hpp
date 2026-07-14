#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool signed_bool;
        const int required_sign;
        const int required_execute;
    public:
        AForm();
        AForm(const std::string &name, int required_sign, int required_execute);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();

        std::string getName() const;
        bool getSignedBool() const;
        int getRequiredSign() const;
        int getRequiredExecute() const;

        void beSigned(const Bureaucrat &bureaucrat);
        virtual void execute(Bureaucrat const & executor) const = 0;

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

    class UnsignedException  : public std::exception
    {
        public:
            const char *what() const throw()
            {
                return("Unsigned form can't be executed!");
            }
    };
};

std::ostream &operator<<(std::ostream &out, const AForm &AForm);

#endif