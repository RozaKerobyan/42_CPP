#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cstdlib>


int main()
{
    PhoneBook pb;
    std::string input;
    
    while (1)
    {
        std::cout << YELLOW << "Enter one of these commands: ADD, SEARCH, or EXIT >>> " << RESET;
        std::getline(std::cin, input);
        if (input == "ADD")
        {
            pb.add_contact();
        }
        else if (input == "SEARCH")
        {
            pb.search_contact();
        }
        else if (input == "EXIT")
            exit(1);
        else
            std::cout << RED << "Invalid command!" << RESET << std::endl;
    }
    return (0);
}