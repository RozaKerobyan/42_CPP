#pragma once

#include <iostream>
#include <sstream>
#include <stack>


class RPN
{
    private:
        std::stack<int> stack;
    public:
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();

        bool isOperator(const std::string &token);
        bool isNumber(const std::string &token);
        void processRPN(const std::string &input);
};