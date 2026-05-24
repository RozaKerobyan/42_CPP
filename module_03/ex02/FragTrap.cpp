#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
    std::cout << "[FragTrap] Default constructor called\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
    std::cout << "[FragTrap] constructor called with a string name for "
    << YELLOW << name << RESET << "\n";
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "[FragTrap] Copy constructor called for "
    << YELLOW << name << RESET << "\n";
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    std::cout << "[FragTrap] Copy assignment operator called for "
    << YELLOW << name << RESET << "\n";
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "[FragTrap] Destructor called for " << YELLOW << name << RESET << "\n";
}

void FragTrap::highFivesGuys(void)
{
    if (hit_points == 0)
    {
        std::cout << "FragTrap " << YELLOW << name << RESET
        << " can't request high fives because it is dead!\n";
        return;
    }
    std::cout << "FragTrap " << YELLOW << name << RESET
    << " requests high fives from everyone!\n";
}