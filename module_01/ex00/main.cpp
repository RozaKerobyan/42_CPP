#include "Zombie.hpp"

int main()
{
    Zombie *heapZombie = newZombie("Heap: ");
    heapZombie->announce();
    delete heapZombie;

    randomChump("Stack: ");
    return (0);
}