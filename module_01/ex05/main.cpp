#include "Harl.hpp"

int	main()
{
	Harl	harl;
    std::string input;

    std::cout << "Enter a command: DEBUG, INFO, WARNING, ERROR, or QUIT." << std::endl;
    while (true)
    {
        getline(std::cin, input);
        if (input == "QUIT")
            exit(1);
        harl.complain(input);
        if (input != "DEBUG" && input != "INFO" && input != "WARNING" && input != "ERROR")
            std::cout << "Invalid command. Please enter DEBUG, INFO, WARNING, ERROR, or QUIT." << std::endl;
    }
	return (0);
}