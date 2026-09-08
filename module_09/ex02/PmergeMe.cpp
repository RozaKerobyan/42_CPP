#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

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

void PmergeMe::pairCreation(const std::string &input)
{

    std::stringstream ss(input);
    std::vector<int> numbers;
    int num;
    while (ss >> num)
    {
        numbers.push_back(num);
    }
    for (size_t i = 0; i + 1 < numbers.size(); i += 2)
    {
        int first = numbers[i];
        int second = numbers[i + 1];
        std::cout << "(" << first << ", " << second << ")" << std::endl;
    }
}