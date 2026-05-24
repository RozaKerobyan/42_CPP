#include "ClapTrap.hpp"

int main()
{
    // Test 1
    ClapTrap a("Icha");
    ClapTrap b("Tapasia");

    std::cout << BLUE << "\n=========== GAME START ===========\n\n" << RESET;

    a.beRepaired(5);

    std::cout << "\n----------------------------------\n\n";

    b.attack("Icha");
    a.takeDamage(20);

    std::cout << "\n----------------------------------\n\n";

    a.attack("Tapasia");
    a.beRepaired(5);

    std::cout << BLUE << "\n=========== GAME END ===========\n" << RESET;

    // Test 2
    ClapTrap soldier("Soldier");

    std::cout << RED << "\n====== DEATH TEST ======\n\n" << RESET;

    soldier.takeDamage(15);

    std::cout << "\n------------------------\n\n";

    soldier.attack("Enemy");

    std::cout << "\n------------------------\n\n";

    soldier.beRepaired(5);

    std::cout << "\n------------------------\n\n";

    soldier.takeDamage(1);

    std::cout << RED << "\n======== END ========\n" << RESET;

    // Test 3

    ClapTrap dog("Dog");

    std::cout << ROSE << "\n====== ENERGY TEST ======\n\n" << RESET;

    for (int i = 0; i < 11; i++)
    {
        dog.attack("Cat");
    }

    std::cout << "\n-------------------------\n\n";

    dog.beRepaired(5);

    std::cout << ROSE << "\n======== END ========\n" << RESET;

    // Test 4
    ClapTrap rembo("Rembo");

    std::cout << GREEN << "\n====== REPAIR TEST ======\n\n" << RESET;

    rembo.beRepaired(50);

    std::cout << "\n-------------------------\n\n";

    rembo.beRepaired(100);

    std::cout << GREEN << "\n======== END ========\n" << RESET;

    return 0;
}