#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    database = other.database;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        database = other.database;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream csv(filename.c_str());
    if (!csv.is_open())
    {
        throw std::runtime_error("Could not open database!");
    }
    std::string line;
    getline(csv, line);
    while (std::getline(csv, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string rate;

        std::getline(ss, date, ',');
        std::getline(ss, rate);

        std::stringstream converter(rate);
        double value;
        converter >> value;
        database[date] = value;
    }
    csv.close();
}

void BitcoinExchange::inputDatabase(const std::string &filename)
{
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open())
    {
        throw std::runtime_error("Could not open input database!");
    }
    std::string line;
    std::getline(inputFile, line);
    if (line != "date | value")
        throw std::runtime_error("Invalid input database format!");
    while (std::getline(inputFile, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string rate;

        std::getline(ss, date, '|');
        std::getline(ss, rate);
        trim(date);
        trim(rate);

        if (!checkDate(date))
        {
            std::cout << "Error: bad input => " << date << "\n";
            continue;
        }
        if (!checkValue(rate))
        {
            std::cout << "Error: bad input => " << rate << "\n";
            continue;
        }
        std::stringstream converter(rate);
        double value;
        converter >> value;
        
        if (value < 0)
        {
            std::cout << "Error: not a positive number.\n";
            continue;
        }
        if (value > 1000)
        {
            std::cout << "Error: too large a number.\n";
            continue;
        }
        double result;
        if (!calculateRate(date, value, result))
        {
            std::cout << "Error: no exchange rate available for this date." << std::endl;
            continue;
        }
        std::cout << date << " => " << value << " = " << result << std::endl;
    }
    inputFile.close();
}

bool BitcoinExchange::checkDate(const std::string &date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return false;
    }

    int year;
    int month;
    int day;
    std::stringstream ss;

    ss.str(date.substr(0, 4));
    ss >> year;
    ss.clear();

    ss.str(date.substr(5, 2));
    ss >> month;
    ss.clear();

    ss.str(date.substr(8, 2));
    ss >> day;

    if (month < 1 || month > 12)
        return false;

    int daysInMonth;
    if (month == 2)
    {
        if ((year % 400 == 0 ) || (year % 4 == 0 && year % 100 != 0))
            daysInMonth = 29;
        else
            daysInMonth = 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        daysInMonth = 30;
    else
        daysInMonth = 31;
    if (day < 1 || day > daysInMonth)
        return false;

    return true;
}

bool BitcoinExchange::checkValue(const std::string &value)
{
    std::stringstream ss(value);
    double num;
    char extra;

    if (!(ss >> num))
        return false;
    if (ss >> extra)
        return false;
    return true;
}

bool BitcoinExchange::calculateRate(const std::string &date, double value, double &result)
{
    std::map<std::string, double>::iterator it;

    it = database.upper_bound(date);
    if (it == database.begin())
        return false;
    --it;
    result = value * it->second;
    
    return true;
}

void BitcoinExchange::trim(std::string &str)
{
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");

    if (start == std::string::npos)
    {
        str.clear();
        return;
    }
    str = str.substr(start, end - start + 1);
}