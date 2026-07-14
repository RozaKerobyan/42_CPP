#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : \
    AForm("Default-Shrubbery", 145, 137), target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : \
    AForm("Shrubbery", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : \
    AForm(other), target(other.target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return(*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!this->getSignedBool())
        throw AForm::UnsignedException();
    if (executor.getGrade() > this->getRequiredExecute())
        throw AForm::GradeTooLowException();

    std::string filename = this->target + "_shrubbery";
    std::ofstream outfile(filename.c_str());
    if (!outfile)
    {
        std::cerr << "Error: Could not create file." << std::endl;
        return;
    }

    outfile << "       _-_" << std::endl;
    outfile << "    /~~   ~~\\" << std::endl;
    outfile << " /~~         ~~\\" << std::endl;
    outfile << "{               }" << std::endl;
    outfile << " \\  _-     -_  /" << std::endl;
    outfile << "   ~  \\\\ //  ~" << std::endl;
    outfile << "_- -   | | _- _" << std::endl;
    outfile << "  _ -  | |   -_" << std::endl;
    outfile << "      // \\\\" << std::endl;

    outfile.close();
}