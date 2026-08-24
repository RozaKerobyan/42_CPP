#pragma once

#include <iostream>

template <typename T>
void iter(T *array, const size_t length, void (*f)(T&))
{
    for (size_t i = 0; i < length; i++)
        f(array[i]);
}

template <typename T>
void print(T &element)
{
    static size_t index = 0;
    std::cout << "index [" << index << "] - " << element << std::endl;
    index++;
}