#include "Form.hpp"

Form::Form() : name("Default"), signed_bool(false), \
    required_sign(10), required_execute(10) {}

Form::Form(const std::string &name, int required_sign, int required_execute) :
    name(name), signed_bool(false), \
    required_sign(required_sign), required_execute(required_execute) 
{
    if (required_sign < 1 || required_execute < 1)
    {
        throw GradeTooHighException();
    }
    if (required_sign > 150 || required_execute > 150)
    {
        throw GradeTooLowException();
    }
    
}

Form::Form(const Form &other) : name(other.name), signed_bool(other.signed_bool), \
    required_sign(other.required_sign), required_execute(other.required_execute) {}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        signed_bool = other.signed_bool;
    }
    return (*this);
}

Form::~Form() {}

std::string Form::getName() const
{
    return (this->name);
}

bool Form::getSignedBool() const
{
    return (this->signed_bool);
}

int Form::getRequiredSign() const
{
    return (this->required_sign);
}

int Form::getRequiredExecute() const
{
    return (this->required_execute);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->required_sign)
    {
        throw GradeTooLowException();
    }
    this->signed_bool = true;
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << "--- Form --- \n" 
        << "Name: " << form.getName() << ", Signed: " << form.getSignedBool() \
        << ", Required Sign Grade: " << form.getRequiredSign() \
        << ", Required Execute Grade: " << form.getRequiredExecute();
    return (out);
}