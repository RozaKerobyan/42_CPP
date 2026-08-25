#include "easyfind.hpp"

int main()
{
    std::vector<int> numbers;

    numbers.push_back(16);
    numbers.push_back(32);
    numbers.push_back(48);

    std::cout << "--- Test 1 ---\n";
    try
    {
        std::vector<int>::iterator it;
        it = easyfind(numbers, 16);
        std::cout << *it << std::endl;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "--- Test 2 ---\n";
    try
    {
        std::vector<int>::iterator it;
        it = easyfind(numbers, 64);
        std::cout << *it << std::endl;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}