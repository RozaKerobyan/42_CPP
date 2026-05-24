#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
    std::cout << "[ScavTrap] Default constructor called\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
    std::cout << "[ScavTrap] constructor called with a string name for "
    << YELLOW << name << RESET << "\n";
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "[ScavTrap] Copy constructor called for "
    << YELLOW << name << RESET << "\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    std::cout << "[ScavTrap] Copy assignment operator called for "
    << YELLOW << name << RESET << "\n";
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "[ScavTrap] Destructor called for " << YELLOW << name << RESET << "\n";
}

void ScavTrap::attack(const std::string& target)
{
    if (hit_points == 0)
    {
        std::cout << "ScavTrap " << YELLOW << name << RESET
        << " can't attack because it is dead!\n";
        return;
    }
    if (energy_points == 0)
    {
        std::cout << "ScavTrap " << YELLOW << name << RESET
        << " can't attack because it has no energy points left!\n";
        return;
    }
    std::cout << "ScavTrap " << YELLOW << name << RESET
    << " attacks " << YELLOW << target << RESET
    << ", causing " << GREEN << attack_damage << RESET
    << " points of damage!\n";

    energy_points--;
}

void ScavTrap::guardGate()
{
    if (hit_points == 0)
    {
        std::cout << "ScavTrap " << YELLOW << name << RESET
        << " can't enter Gate keeper mode because it is dead!\n";
        return ;
    }
    std::cout << "ScavTrap " << YELLOW << name << RESET
    << " has entered Gate keeper mode!\n";
}