#include "FragTrap.hpp"

int main()
{
    std::cout << ROSE
    << "\n========== FRAGTRAP TEST ==========\n\n"
    << RESET;

    // Constructor test
    FragTrap hero("Hero");
    FragTrap enemy("Enemy");

    std::cout << "\n-----------------------------------\n\n";

    // Attack test
    hero.attack("Enemy");
    enemy.takeDamage(30);

    std::cout << "\n-----------------------------------\n\n";

    // Repair test
    hero.beRepaired(40);

    std::cout << "\n-----------------------------------\n\n";

    // Special ability
    hero.highFivesGuys();

    std::cout << "\n-----------------------------------\n\n";

    // Enemy attacks back
    enemy.attack("Hero");
    hero.takeDamage(25);

    std::cout << "\n-----------------------------------\n\n";

    // Death test
    hero.takeDamage(200);

    std::cout << "\n-----------------------------------\n\n";

    // Dead state test
    hero.attack("Enemy");
    hero.beRepaired(10);
    hero.highFivesGuys();

    std::cout << ROSE
    << "\n=========== END TEST =============\n"
    << RESET;

    return (0);
}