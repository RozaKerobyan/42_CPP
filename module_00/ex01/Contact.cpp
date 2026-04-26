#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void Contact::set_first_name(std::string set_first_name)
{
    first_name = set_first_name;
}

void Contact::set_last_name(std::string set_last_name)
{
    last_name = set_last_name;
}

void Contact::set_nickname(std::string set_nickname)
{
    nickname = set_nickname;
}

void Contact::set_phone_number(std::string set_phone_number)
{
    phone_number = set_phone_number;
}

void Contact::set_darkest_secret(std::string set_darkest_secret)
{
    darkest_secret = set_darkest_secret;
}

std::string Contact::get_first_name()
{
    return (this->first_name);
}

std::string Contact::get_last_name()
{
    return (this->last_name);
}

std::string Contact::get_nickname()
{
    return (this->nickname);
}

std::string Contact::get_phone_number()
{
    return (this->phone_number);
}

std::string Contact::get_darkest_secret()
{
    return (this->darkest_secret);
}