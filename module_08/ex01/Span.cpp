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
    if (numbers.size() < 2)
        throw SpanException();
    
    std::vector<int> tmp = numbers;
    std::sort(tmp.begin(), tmp.end());

    int shortest = tmp[1] - tmp[0];
    for (size_t i = 1; i < tmp.size(); i++)
    {
        int span = tmp[i] - tmp[i - 1];
        if (span < shortest)
            shortest = span;
    }
    return (shortest);
}

int Span::longestSpan()
{
    if (numbers.size() < 2)
        throw SpanException();
    int max = *std::max_element(numbers.begin(), numbers.end());
    int min = *std::min_element(numbers.begin(), numbers.end());

    return (max-min);
}
