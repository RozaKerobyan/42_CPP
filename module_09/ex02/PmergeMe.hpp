#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <iomanip>
#include <ctime>

class PmergeMe
{
    private:
        std::vector<int> vector;
        std::deque<int> deque;

        int vectorStraggler;
        int dequeStraggler;

        int hasVectorStraggler;
        int hasDequeStraggler;

        std::vector<int> vectorGreater;
        std::deque<int> dequeGreater;

        std::vector<int> vectorLesser;
        std::deque<int> dequeLesser;
    private:
        std::vector<int> fordJohnsonVector(const std::vector<int> &input);
        std::deque<int> fordJohnsonDeque(const std::deque<int> &input);

        void insertVectorValue(std::vector<int> &result, int value, size_t end);
        void insertDequeValue(std::deque<int> &result, int value, size_t end);

        std::vector<size_t> createJacobsthalOrderVector(size_t size);
        std::deque<size_t> createJacobsthalOrderDeque(size_t size);

        void reset();
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        bool checkInputs(const std::string &input);
        bool parseInput(int argc, char **argv);
        void sortVector();
        void sortDeque();
        void sort();
        const std::vector<int> &getVector() const;
        const std::deque<int> &getDeque() const;
};