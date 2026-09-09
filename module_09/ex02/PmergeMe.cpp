#include "PmergeMe.hpp"

PmergeMe::PmergeMe() 
{
    vectorStraggler = 0;
    dequeStraggler = 0;
    hasVectorStraggler = false;
    hasDequeStraggler = false;
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    vector = other.vector;
    deque = other.deque;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        vector = other.vector;
        deque = other.deque;
    }
    return (*this);
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::checkInputs(const std::string &input)
{
    if (input.empty())
        return (false);
    else if (input[0] == '-')
        return (false);
    else if (input[0] >= 'a' && input[0] <= 'z')
        return (false);
    else if (input[0] >= 'A' && input[0] <= 'Z')
        return (false);
    return (true);
}

void PmergeMe::pairCreationVector(const std::string &input)
{

    std::stringstream ss(input);
    int num;

    while (ss >> num)
    {
        vector.push_back(num);
    }
    for (size_t i = 0; i + 1 < vector.size(); i += 2)
    {
        int first = vector[i];
        int second = vector[i + 1];
        
        if (first < second)
            vectorPairs.push_back(std::make_pair(second, first));
        else
            vectorPairs.push_back(std::make_pair(first, second));
    }
    if (vector.size() % 2 != 0)
    {
        vectorStraggler = vector.back();
        hasVectorStraggler = true;
    }
}

void PmergeMe::pairCreationDeque(const std::string &input)
{

    std::stringstream ss(input);
    int num;

    while (ss >> num)
    {
        deque.push_back(num);
    }
    for (size_t i = 0; i + 1 < deque.size(); i += 2)
    {
        int first = deque[i];
        int second = deque[i + 1];
        
        if (first < second)
            dequePairs.push_back(std::make_pair(second, first));
        else
            dequePairs.push_back(std::make_pair(first, second));
    }
    if (deque.size() % 2 != 0)
    {
        dequeStraggler = deque.back();
        hasDequeStraggler = true;
    }
}

void PmergeMe::separateVectorPairs()
{
    for (size_t i = 0; i < vectorPairs.size(); i++)
    {
        vectorGreater.push_back(vectorPairs[i].first);
        vectorLesser.push_back(vectorPairs[i].second);
    }
}

void PmergeMe::separateDequePairs()
{
    for (size_t i = 0; i < dequePairs.size(); i++)
    {
        dequeGreater.push_back(dequePairs[i].first);
        deque.push_back(dequePairs[i].second);
    }
}