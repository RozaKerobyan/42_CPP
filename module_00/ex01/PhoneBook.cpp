#include "PhoneBook.hpp"

PhoneBook::PhoneBook() 
{
    size = 0;
    index = 0;
}

PhoneBook::~PhoneBook() {}

bool is_number(std::string input)
{
    size_t i;

    i = 0;
    if (input.empty())
        return false;
    while (i < input.length())
    {
        if (!isdigit(input[i]))
            return false;
        i++;
    }
    return true;
}

void PhoneBook::add_contact()
{
    Contact person;
    std::string input;

    while (1)
    {
        std::cout << BLUE << "First name: " << RESET;
        std::getline(std::cin, input);
        if (input.empty())
        {
            std::cout << RED << "Empty not allowed!" << RESET << std::endl;
            continue;
        }
        if (is_number(input))
        {
            std::cout << RED << "Number not allowed!" << RESET << std::endl;
            continue;
        }
        person.set_first_name(input);
        break;
    }

    while (1)
    {
        std::cout << BLUE << "Last name: " << RESET;
        std::getline(std::cin, input);
        if (input.empty())
        {
            std::cout << RED << "Empty not allowed!" << RESET << std::endl;
            continue;
        }
        if (is_number(input))
        {
            std::cout << RED << "Number not allowed!" << RESET << std::endl;
            continue;
        }
        person.set_last_name(input);
        break;;
    }

    while (1)
    {
        std::cout << BLUE << "Nickname: " << RESET;
        std::getline(std::cin, input);
        if (input.empty())
        {
            std::cout << RED << "Empty not allowed!" << RESET << std::endl;
            continue;
        }
        if (is_number(input))
        {
            std::cout << RED << "Number not allowed!" << RESET << std::endl;
            continue;
        }
        person.set_nickname(input);
        break;;
    }

    while (1)
    {
        std::cout << BLUE << "Phone number: " << RESET;
        std::getline(std::cin, input);
        if (input.empty())
        {
            std::cout << RED << "Empty not allowed!" << RESET << std::endl;
            continue;
        }
        if (!is_number(input))
        {
            std::cout << RED << "Only number allowed!" << RESET << std::endl;
            continue;
        }
        person.set_phone_number(input);
        break;
    }

    while (1)
    {
        std::cout << BLUE << "Darkest secret: " << RESET;
        std::getline(std::cin, input);
        if (input.empty())
        {
            std::cout << RED << "Empty not allowed!" << RESET << std::endl;
            continue;
        }
        if (is_number(input))
        {
            std::cout << RED << "Number not allowed!" << RESET << std::endl;
            continue;
        }
        person.set_darkest_secret(input);
        break;;
    }
    std::cout << GREEN << ">>> Successfully added <<<" << RESET << std::endl;
    contacts[index] = person;
    index = (index + 1) % 8;
    if (size < 8)
        size++;
}

void PhoneBook::search_contact()
{
    std::string input;
    int idx;

    std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;

    for (int i = 0; i < size; i++)
    {
        if (contacts[i].get_first_name().length() > 10)
            contacts[i].set_first_name(contacts[i].get_first_name().substr(0, 9) + ".");
        if (contacts[i].get_last_name().length() > 10)
            contacts[i].set_last_name(contacts[i].get_last_name().substr(0, 9) + ".");
        if (contacts[i].get_nickname().length() > 10)
            contacts[i].set_nickname(contacts[i].get_nickname().substr(0, 9) + ".");
        std::cout << "|"
        << std::setw(10) << i << "|"
        << std::setw(10) << contacts[i].get_first_name() << "|"
        << std::setw(10) << contacts[i].get_last_name() << "|"
        << std::setw(10) << contacts[i].get_nickname() << "|"
        << std::endl;
        std::cout << "+----------+----------+----------+----------+" << std::endl;
    }
    std::cout << YELLOW << "Enter an index from the table to get information >>> " << RESET;
    std::getline(std::cin, input);
    if (input.empty() || !is_number(input))
    {
        std::cout << RED << "Invalid input!" << RESET << std::endl;
        return;
    }
    idx = std::atoi(input.c_str());
    if (idx >= 0 && idx < size)
    {
        std::cout << YELLOW << "--- CONTACT INFO ---" << RESET << std::endl;
        std::cout << BLUE << "First name: " << RESET << contacts[idx].get_first_name() << std::endl;
        std::cout << BLUE << "Last name: " << RESET << contacts[idx].get_last_name() << std::endl;
        std::cout << BLUE << "Nickname: " << RESET << contacts[idx].get_nickname() << std::endl;
        std::cout << BLUE << "Phone number: " << RESET << contacts[idx].get_phone_number() << std::endl;
        std::cout << BLUE << "Darkest secret: " << RESET << contacts[idx].get_darkest_secret() << std::endl;
    }
    else
        std::cout << RED << "Invalid index!" << RESET << std::endl;
}

