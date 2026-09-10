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

        std::vector<std::pair<int, int>> vectorPairs;
        std::deque<std::pair<int, int>> dequePairs;

        int vectorStraggler;
        int dequeStraggler;

        int hasVectorStraggler;
        int hasDequeStraggler;

        std::vector<int> vectorGreater;
        std::deque<int> dequeGreater;

        std::vector<int> vectorLesser;
        std::deque<int> dequeLesser;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        bool checkInputs(const std::string &input);

        void pairCreationVector(const std::string &input);
        void pairCreationDeque(const std::string &input);

        void separateVectorPairs();
        void separateDequePairs();

        void sortVectorPairs();
        void sortDequePairs();

        void insertVectorValue(int value);
        void insertDequeValue(int value);
};