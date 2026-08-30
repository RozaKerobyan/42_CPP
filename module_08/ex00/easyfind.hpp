#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class NotFoundException  : public std::exception
{
        public:
            const char *what() const throw()
            {
                return("Exception: Not found element!!!");
            }
};

template <typename T>
typename T::iterator easyfind(T &container, int target)
{
    typename T::iterator it = std::find(container.begin(), container.end(), target);
    if (it == container.end())
        throw NotFoundException();
    return (it); 
}