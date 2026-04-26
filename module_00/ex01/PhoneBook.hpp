#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <cstdlib>
#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
        int index;
        int size;
    public:
        PhoneBook();
        ~PhoneBook();
        void add_contact();
        void search_contact();
};

#endif