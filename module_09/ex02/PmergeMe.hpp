#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>


class PmergeMe
{
    private:
        std::vector<int> vector;
        std::deque<int> deque;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        bool checkInputs(const std::string &input);
        void pairCreation(const std::string &input);
};