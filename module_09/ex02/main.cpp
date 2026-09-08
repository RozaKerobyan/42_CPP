#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Invalid argument!\n";
        return (1);
    }
    PmergeMe test;
    test.pairCreation(argv[1]);
}