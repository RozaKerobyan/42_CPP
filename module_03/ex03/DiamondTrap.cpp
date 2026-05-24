#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap(), name("Default")
{
    hit_points = 100;
    energy_points = 50;
    attack_damage = 30;
    std::cout << "[DiamondTrap] Default constructor called\n";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
    hit_points = 100;
    energy_points = 50;
    attack_damage = 30;
    std::cout << "[DiamondTrap] constructor called with a string name for "
    << YELLOW << name << RESET << "\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name)
{
    std::cout << "[DiamondTrap] Copy constructor called for "
    << YELLOW << name << RESET << "\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    std::cout << "[DiamondTrap] Copy assignment operator called for "
    << YELLOW << name << RESET << "\n";
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "[DiamondTrap] Destructor called for " << YELLOW << name << RESET << "\n";
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << YELLOW << name << RESET
    << ", ClapTrap name: " << YELLOW << ClapTrap::name << RESET << "\n";
}