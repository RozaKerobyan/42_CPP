#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>

template <typename T>
class Array
{
    private:
        T *data;
        unsigned int length;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &other);
        Array &operator=(const Array &other);
        ~Array();

        T &operator[](unsigned int index);
        const T &operator[](unsigned int index) const;
        unsigned int size() const;

    class OutOfBoundsException  : public std::exception
    {
        public:
            const char *what() const throw()
            {
                return("Index is out of bounds!!!");
            }
    };
};

#include "Array.tpp"