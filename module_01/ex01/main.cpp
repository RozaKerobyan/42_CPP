#include "Zombie.hpp"

int main()
{
    Zombie *horde = zombieHorde(4, "Zombie: ");
    for (int i = 0; i < 4; i++)
    {
        horde[i].announce();
    }
    delete[] horde;
    return (0);
}