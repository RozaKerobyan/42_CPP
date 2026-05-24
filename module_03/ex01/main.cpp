#include "ScavTrap.hpp"

int main()
{
    std::cout << BLUE
    << "\n========== SCAVTRAP TEST ==========\n\n"
    << RESET;

    // Constructor test
    ScavTrap hero("Hero");
    ScavTrap enemy("Enemy");

    std::cout << "\n-----------------------------------\n\n";

    // Attack test and damage test
    hero.attack("Enemy");
    enemy.takeDamage(20);

    std::cout << "\n-----------------------------------\n\n";

    // Repair test
    hero.beRepaired(25);

    std::cout << "\n-----------------------------------\n\n";

    // Guard Gate mode
    hero.guardGate();

    std::cout << "\n-----------------------------------\n\n";

    // Enemy attacks back
    enemy.attack("Hero");
    hero.takeDamage(15);

    std::cout << "\n-----------------------------------\n\n";

    // Death test
    hero.takeDamage(200);

    std::cout << "\n-----------------------------------\n\n";

    // Dead state test
    hero.attack("Enemy");
    hero.beRepaired(10);
    hero.guardGate();

    std::cout << BLUE
    << "\n=========== END TEST =============\n"
    << RESET;

    return (0);
}