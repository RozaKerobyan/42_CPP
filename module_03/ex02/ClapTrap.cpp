#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "[ClapTrap] Default constructor called\n";
}

ClapTrap::ClapTrap(std::string name) : name(name), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "[ClapTrap] constructor called with a string name for "
    << YELLOW << name << RESET << "\n";
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    name = other.name;
    hit_points = other.hit_points;
    energy_points = other.energy_points;
    attack_damage = other.attack_damage;
    std::cout << "[ClapTrap] Copy constructor called for "
    << YELLOW << name << RESET << "\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        name = other.name;
        hit_points = other.hit_points;
        energy_points = other.energy_points;
        attack_damage = other.attack_damage;
    }
    std::cout << "[ClapTrap] Copy assignment operator called for "
    << YELLOW << name << RESET << "\n";
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "[ClapTrap] Destructor called for " << YELLOW << name << RESET << "\n";
}

void ClapTrap::attack(const std::string& target)
{
    if (hit_points == 0)
    {
        std::cout << "ClapTrap " << YELLOW << name << RESET
        << " can't attack because it is dead!\n";
        return;
    }
    if (energy_points == 0)
    {
        std::cout << "ClapTrap " << YELLOW << name << RESET
        << " can't attack because it has no energy points left!\n";
        return;
    }
    std::cout << "ClapTrap " << YELLOW << name << RESET
    << " attacks " << YELLOW << target << RESET
    << ", causing " << GREEN << attack_damage << RESET
    << " points of damage!\n";

    energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hit_points == 0)
    {
        std::cout << "ClapTrap " << YELLOW << name << RESET
        << " is already dead!\n";
        return;
    }
    if (hit_points <= amount)
    {
        hit_points = 0;
        std::cout << "ClapTrap " << YELLOW << name << RESET
        << " takes " << GREEN << amount << RESET
        << " points of damage and is now dead!\n";
    }
    else
    {
        hit_points -= amount;
        std::cout << "ClapTrap " << YELLOW << name << RESET
        << " takes " << GREEN << amount << RESET
        << " points of damage! Remaining hit points: "
        << GREEN << hit_points << RESET << "\n";
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hit_points == 0)
    {
        std::cout << "ClapTrap " << YELLOW << name << RESET
        << " can't be repaired because it is dead!\n";
        return;
    }
    if (energy_points == 0)
    {
        std::cout << "ClapTrap " << YELLOW << name << RESET
        << " can't be repaired because it has no energy points left!\n";
        return;
    }
    hit_points += amount;
    energy_points--;

    std::cout << "ClapTrap " << YELLOW << name << RESET
    << " is repaired by " << GREEN << amount << RESET
    << " points! Current hit points: "
    << GREEN << hit_points << RESET << "\n";
}