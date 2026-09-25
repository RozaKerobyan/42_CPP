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
    vectorGreater = other.vectorGreater;
    vectorLesser = other.vectorLesser;
    dequeGreater = other.dequeGreater;
    dequeLesser = other.dequeLesser;
    vectorStraggler = other.vectorStraggler;
    dequeStraggler = other.dequeStraggler;
    hasVectorStraggler = other.hasVectorStraggler;
    hasDequeStraggler = other.hasDequeStraggler;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        vector = other.vector;
        deque = other.deque;
        vectorGreater = other.vectorGreater;
        vectorLesser = other.vectorLesser;
        dequeGreater = other.dequeGreater;
        dequeLesser = other.dequeLesser;
        vectorStraggler = other.vectorStraggler;
        dequeStraggler = other.dequeStraggler;
        hasVectorStraggler = other.hasVectorStraggler;
        hasDequeStraggler = other.hasDequeStraggler;
    }
    return (*this);
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::checkInputs(const std::string &input)
{
    size_t i;
    long value;

    if (input.empty())
        return (false);
    i = 0;
    if (input[0] == '+')
        i = 1;
    if (i == input.size())
        return (false);
    while (i < input.size())
    {
        if (input[i] < '0' || input[i] > '9')
            return (false);
        i++;
    }

    std::stringstream ss(input);
    ss >> value;
    if (ss.fail() || value > 2147483647)
        return (false);
    return (true);
}

bool PmergeMe::parseInput(int argc, char **argv)
{
    int i;

    reset();
    if (argc < 2)
        return (false);
    i = 1;
    while (i < argc)
    {
        if (!checkInputs(argv[i]))
            return (false);
        vector.push_back(atoi(argv[i]));
        deque.push_back(atoi(argv[i]));
        i++;
    }
    return (true);
}

void PmergeMe::reset()
{
    vector.clear();
    deque.clear();
    vectorGreater.clear();
    vectorLesser.clear();
    dequeGreater.clear();
    dequeLesser.clear();
    vectorStraggler = 0;
    dequeStraggler = 0;
    hasVectorStraggler = false;
    hasDequeStraggler = false;
}

std::vector<int> PmergeMe::fordJohnsonVector(const std::vector<int> &input)
{
    std::vector<std::pair<int, int> > pairs;
    std::vector<std::pair<int, int> > orderedPairs;
    std::vector<int> winners;
    std::vector<int> sortedWinners;
    std::vector<int> result;
    std::vector<size_t> order;
    size_t i;
    size_t j;
    size_t winnerPosition;
    size_t index;
    int first;
    int second;
    int straggler;

    if (input.size() <= 1)
        return (input);
    i = 0;
    while (i + 1 < input.size())
    {
        first = input[i];
        second = input[i + 1];
        if (first < second)
            pairs.push_back(std::make_pair(second, first));
        else
            pairs.push_back(std::make_pair(first, second));
        i += 2;
    }
    straggler = 0;
    if (input.size() % 2 != 0)
        straggler = input.back();
    i = 0;
    while (i < pairs.size())
    {
        winners.push_back(pairs[i].first);
        i++;
    }
    sortedWinners = fordJohnsonVector(winners);
    i = 0;
    while (i < sortedWinners.size())
    {
        j = 0;
        while (j < pairs.size())
        {
            if (pairs[j].first == sortedWinners[i])
            {
                orderedPairs.push_back(pairs[j]);
                pairs.erase(pairs.begin() + j);
                break;
            }
            j++;
        }
        i++;
    }
    if (!orderedPairs.empty())
        result.push_back(orderedPairs[0].second);

    i = 0;
    while (i < sortedWinners.size())
    {
        result.push_back(sortedWinners[i]);
        i++;
    }
    order = createJacobsthalOrderVector(orderedPairs.size());
    i = 0;
    while (i < order.size())
    {
        index = order[i];
        if (index != 0 && index < orderedPairs.size())
        {
            winnerPosition = 0;
            while (winnerPosition < result.size()
                && result[winnerPosition] != orderedPairs[index].first)
                winnerPosition++;
            insertVectorValue(result, orderedPairs[index].second, winnerPosition);
        }
        i++;
    }
    if (input.size() % 2 != 0)
        insertVectorValue(result, straggler, result.size());
    return (result);
}

std::deque<int> PmergeMe::fordJohnsonDeque(const std::deque<int> &input)
{
    std::deque<std::pair<int, int> > pairs;
    std::deque<std::pair<int, int> > orderedPairs;
    std::deque<int> winners;
    std::deque<int> sortedWinners;
    std::deque<int> result;
    std::deque<size_t> order;
    size_t i;
    size_t j;
    size_t winnerPosition;
    size_t index;
    int first;
    int second;
    int straggler;

    if (input.size() <= 1)
        return (input);
    i = 0;
    while (i + 1 < input.size())
    {
        first = input[i];
        second = input[i + 1];
        if (first < second)
            pairs.push_back(std::make_pair(second, first));
        else
            pairs.push_back(std::make_pair(first, second));
        i += 2;
    }
    straggler = 0;
    if (input.size() % 2 != 0)
        straggler = input.back();

    i = 0;
    while (i < pairs.size())
    {
        winners.push_back(pairs[i].first);
        i++;
    }
    sortedWinners = fordJohnsonDeque(winners);
    i = 0;
    while (i < sortedWinners.size())
    {
        j = 0;
        while (j < pairs.size())
        {
            if (pairs[j].first == sortedWinners[i])
            {
                orderedPairs.push_back(pairs[j]);
                pairs.erase(pairs.begin() + j);
                break;
            }
            j++;
        }
        i++;
    }
    if (!orderedPairs.empty())
        result.push_back(orderedPairs[0].second);
    i = 0;
    while (i < sortedWinners.size())
    {
        result.push_back(sortedWinners[i]);
        i++;
    }
    order = createJacobsthalOrderDeque(orderedPairs.size());
    i = 0;
    while (i < order.size())
    {
        index = order[i];
        if (index != 0 && index < orderedPairs.size())
        {
            winnerPosition = 0;
            while (winnerPosition < result.size()
                && result[winnerPosition] != orderedPairs[index].first)
                winnerPosition++;
            insertDequeValue(result, orderedPairs[index].second, winnerPosition);
        }
        i++;
    }
    if (input.size() % 2 != 0)
        insertDequeValue(result, straggler, result.size());
    return (result);
}

std::vector<size_t> PmergeMe::createJacobsthalOrderVector(size_t size)
{
    std::vector<size_t> order;
    size_t prev;
    size_t curr;
    size_t next;
    size_t end;
    size_t i;

    if (size == 0)
        return (order);
    order.push_back(0);
    prev = 1;
    curr = 3;
    while (prev < size)
    {
        end = curr;
        if (end > size)
            end = size;
        i = end;
        while (i > prev)
        {
            order.push_back(i - 1);
            i--;
        }
        next = curr + 2 * prev;
        prev = curr;
        curr = next;
    }
    return (order);
}

std::deque<size_t> PmergeMe::createJacobsthalOrderDeque(size_t size)
{
    std::deque<size_t> order;
    size_t prev;
    size_t curr;
    size_t next;
    size_t end;
    size_t i;

    if (size == 0)
        return (order);
    order.push_back(0);
    prev = 1;
    curr = 3;
    while (prev < size)
    {
        end = curr;
        if (end > size)
            end = size;
        i = end;
        while (i > prev)
        {
            order.push_back(i - 1);
            i--;
        }
        next = curr + 2 * prev;
        prev = curr;
        curr = next;
    }
    return (order);
}

void PmergeMe::insertVectorValue(std::vector<int> &result, int value, size_t end)
{
    size_t left = 0;
    size_t right = end;
    size_t middle;

    while (left < right)
    {
        middle = left + (right - left) / 2;
        if (result[middle] < value)
            left = middle + 1;
        else
            right = middle;
    }
    result.insert(result.begin() + left, value);
}

void PmergeMe::insertDequeValue(std::deque<int> &result, int value, size_t end)
{
    size_t left = 0;
    size_t right = end;
    size_t middle;

    while (left < right)
    {
        middle = left + (right - left) / 2;
        if (result[middle] < value)
            left = middle + 1;
        else
            right = middle;
    }
    result.insert(result.begin() + left, value);
}

void PmergeMe::sortVector()
{
    vectorGreater.clear();
    vectorGreater = fordJohnsonVector(vector);
}

void PmergeMe::sortDeque()
{
    dequeGreater.clear();
    dequeGreater = fordJohnsonDeque(deque);
}

void PmergeMe::sort()
{
    sortVector();
    sortDeque();
}

const std::vector<int> &PmergeMe::getVector() const
{
    return (vectorGreater);
}

const std::deque<int> &PmergeMe::getDeque() const
{
    return (dequeGreater);
}