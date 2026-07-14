#include "AForm.hpp"

AForm::AForm() : name("Default"), signed_bool(false), \
    required_sign(10), required_execute(10) {}

AForm::AForm(const std::string &name, int required_sign, int required_execute) :
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

AForm::AForm(const AForm &other) : name(other.name), signed_bool(other.signed_bool), \
    required_sign(other.required_sign), required_execute(other.required_execute) {}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        signed_bool = other.signed_bool;
    }
    return (*this);
}

AForm::~AForm() {}

std::string AForm::getName() const
{
    return (this->name);
}

bool AForm::getSignedBool() const
{
    return (this->signed_bool);
}

int AForm::getRequiredSign() const
{
    return (this->required_sign);
}

int AForm::getRequiredExecute() const
{
    return (this->required_execute);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->required_sign)
    {
        throw GradeTooLowException();
    }
    this->signed_bool = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!this->signed_bool)
    {
        throw UnsignedException();
    }
    if (executor.getGrade() > this->required_execute)
    {
        throw GradeTooLowException();
    }
}

std::ostream &operator<<(std::ostream &out, const AForm &AForm)
{
    out << "--- AForm --- \n" 
        << "Name: " << AForm.getName() << ", Signed: " << AForm.getSignedBool() \
        << ", Required Sign Grade: " << AForm.getRequiredSign() \
        << ", Required Execute Grade: " << AForm.getRequiredExecute();
    return (out);
}