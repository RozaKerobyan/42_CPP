#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "<<< TEST 1: Invalid form (grade too low) >>>" << std::endl;
    try
    {
        Form form("Icha", 170, 3);
        std::cout << form << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\n<<< TEST 2: Invalid form (grade too high) >>>" << std::endl;
    try
    {
        Form form("Icha", -1, 190);
        std::cout << form << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\n<<< TEST 3: Valid form >>>" << std::endl;
    try
    {
        Form form("Mr. Bean", 50, 100);
        std::cout << form << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\n<<< TEST 4: Successful sign >>>" << std::endl;
    try
    {
        Bureaucrat bureaucrat("Tom", 20);
        Form form("Jerry", 50, 100);

        std::cout << bureaucrat << std::endl;
        std::cout << form << std::endl;

        bureaucrat.signForm(form);

        std::cout << form << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\n<<< TEST 5: Failed sign >>>" << std::endl;
    try
    {
        Bureaucrat bureaucrat("Rembo", 100);
        Form form("Vandam", 50, 100);

        std::cout << bureaucrat << std::endl;
        std::cout << form << std::endl;

        bureaucrat.signForm(form);

        std::cout << form << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\n<<< TEST 6: Already signed >>>" << std::endl;
    try
    {
        Bureaucrat bureaucrat("Dog", 1);
        Form form("Cat", 5, 10);

        bureaucrat.signForm(form);
        std::cout << form << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return (0);
} 