#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : \
    AForm("Default-Robotomy", 72, 45), target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : \
    AForm("Robotomy", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : \
    AForm(other), target(other.target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return(*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!this->getSignedBool())
        throw AForm::UnsignedException();
    if (executor.getGrade() > this->getRequiredExecute())
        throw AForm::GradeTooLowException();

    std::cout << "Drilling noises..." << std::endl;
    if (std::rand() % 2)
        std::cout << this->target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed on " << this->target << "!" << std::endl;
}
