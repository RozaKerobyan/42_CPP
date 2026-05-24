#include "DiamondTrap.hpp"

int main()
{
    std::cout << BLUE
    << "\n========== DIAMONDTRAP TEST ==========\n\n"
    << RESET;

    // Constructor test
    DiamondTrap hero("Hero");
    DiamondTrap enemy("Enemy");

    std::cout << "\n-----------------------------------\n\n";

    // WhoAmI test 
    hero.whoAmI();

    std::cout << "\n-----------------------------------\n\n";

    // Attack test from ScavTrap
    hero.attack("Enemy");
    enemy.takeDamage(30);

    std::cout << "\n-----------------------------------\n\n";

    // Repair test from ClapTrap logic
    hero.beRepaired(40);

    std::cout << "\n-----------------------------------\n\n";

    //Special FragTrap ability OR ScavTrap ability usage mix
    hero.guardGate();   
    hero.highFivesGuys();

    std::cout << "\n-----------------------------------\n\n";

    // Enemy counter attack
    enemy.attack("Hero");
    hero.takeDamage(50);

    std::cout << "\n-----------------------------------\n\n";

    // Death test
    hero.takeDamage(200);

    std::cout << "\n-----------------------------------\n\n";

    // Dead state test
    hero.attack("Enemy");
    hero.beRepaired(10);
    hero.guardGate();
    hero.highFivesGuys();
    hero.whoAmI();

    std::cout << BLUE
    << "\n=========== END TEST =============\n"
    << RESET;

    return 0;
}