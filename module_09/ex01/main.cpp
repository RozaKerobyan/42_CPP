#include "RPN.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Invaild input!\n";
        return (1);
    }
    RPN test;
    test.processRPN(argv[1]);
    return (0);
}