#pragma once

#include <iostream>
#include <cstring>
#include <limits>
#include <iomanip>
#include <sstream>
#include <climits>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();

        static void convertFromChar(const std::string &literal);
        static void convertFromInt(const std::string &literal);
        static void convertFromFloat(const std::string &literal);
        static void convertFromDouble(const std::string &literal);
        static void convertFromInfNan(const std::string &literal);
    public:
        static void convert(const std::string &literal);
};
