#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define ROSE "\033[1;38;5;205m"

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap 
{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap& other);
        FragTrap& operator=(const FragTrap& other);
        ~FragTrap();

        void highFivesGuys(void);

};

#endif