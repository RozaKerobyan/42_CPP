#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <map>
#include <sstream>
#include <cctype>

class BitcoinExchange
{
    private:
        std::map<std::string, double> database;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        void loadDatabase(const std::string &filename);
        void inputDatabase(const std::string &filename);
    private:
        void trim(std::string &str);
        bool checkDate(const std::string &date);
        bool checkValue(const std::string &value);
        bool calculateRate(const std::string &date, double value, double &result);
};