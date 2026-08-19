#pragma once

#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
const T &max(T &x, T &y)
{
    if (x > y)
        return (x);
    else
        return (y);
}

template <typename T>
const T &min(T &x, T &y)
{
    if (x > y)
        return (y);
    else
        return (x);
}
