#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other)
{
    stack = other.stack;
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        stack = other.stack;
    }
    return (*this);
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string &token)
{
    if (token == "*" || token == "/" || token == "+" || token == "-")
    {
        return (true);
    }
    return (false);
}

bool RPN::isNumber(const std::string &token)
{
    if (token.length() == 1 && token[0] >= '0' && token[0] <='9')
    {
        return (true);
    }
    return (false);
}

void RPN::processRPN(const std::string &input)
{
    std::stringstream ss(input);
    std::string token;

    while (!stack.empty())
        stack.pop();
    while (ss >> token)
    {
        if (isNumber(token))
        {
            int num = token[0] - '0';
            stack.push(num);
        }
        else if (isOperator(token))
        {
            if (stack.size() < 2)
            {
                std::cerr << "Error: Invalid RPN expression!\n"; 
                return ;
            }
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();

            if (token == "+")
                stack.push(a + b);
            else if (token == "-")
                stack.push(a - b);
            else if (token == "*")
                stack.push(a * b);
            else if (token == "/")
            {
                if (b == 0)
                {
                    std::cerr << "Error: Division by zero is not allowed.\n";
                    return ;
                }
                stack.push(a / b);
            }
        }
        else
        {
            std::cerr << "Error: Invalid token!\n";
            return ;
        }
    }
    if (stack.size() != 1)
    {
        std::cerr << "Error: Invalid RPN expression!\n";
        return ;
    }
    std::cout << stack.top() << std::endl;
}
