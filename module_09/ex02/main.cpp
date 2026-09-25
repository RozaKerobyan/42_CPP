#include "PmergeMe.hpp"

void printBefore(int argc, char **argv)
{
    std::cout << "Before: ";

    for (int i = 1; i < argc; i++)
        std::cout << argv[i] << " ";
    std::cout << std::endl;
}

void printAfter(const std::vector<int> &result)
{
    std::cout << "After:  ";

    for (size_t i = 0; i < result.size(); i++)
        std::cout << result[i] << " ";
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    PmergeMe pmerge;
    clock_t startVector;
    clock_t endVector;
    clock_t startDeque;
    clock_t endDeque;
    double vectorTime;
    double dequeTime;

    if (!pmerge.parseInput(argc, argv))
    {
        std::cerr << "Error" << std::endl;
        return (1);
    }
    printBefore(argc, argv);

    startVector = clock();
    pmerge.sortVector();
    endVector = clock();

    startDeque = clock();
    pmerge.sortDeque();
    endDeque = clock();

    printAfter(pmerge.getVector());
    vectorTime = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1000000;
    dequeTime = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::[vector] : "
              << std::fixed << std::setprecision(5) << vectorTime << " us" << std::endl;

    std::cout << "Time to process a range of " << argc - 1 << " elements with std::[deque] : "
              << std::fixed << std::setprecision(5) << dequeTime << " us" << std::endl;
    return (0);
}