#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class FullException  : public std::exception
{
        public:
            const char *what() const throw()
            {
                return("NOT FOUND ELEMENT!!!");
            }
};

class Span
{
    private:
        unsigned int maxSize;
        std::vector<int> numbers;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int i);
        int shortestSpan();
        int longestSpan();
};