#include "Span.hpp"

Span::Span() 
{
    maxSize = 0;
}

Span::Span(unsigned int N) 
{
    maxSize = N;
}

Span::Span(const Span &other) 
{
    maxSize = other.maxSize;
    numbers = other.numbers;
}

Span &Span::operator=(const Span &other) 
{
    if (this != &other)
    {
        maxSize = other.maxSize;
        numbers = other.numbers;
    }
    return (*this);
}

Span::~Span() {}

void Span::addNumber(int i)
{
    if (numbers.size() >= maxSize)
        throw FullException();
    numbers.push_back(i);
}

int Span::shortestSpan() 
{
    // here to write logic
}

int Span::longestSpan()
{
    int max = *std::max_element(numbers.begin(), numbers.end());
    int min = *std::min_element(numbers.begin(), numbers.end());

    return (max-min);
}
