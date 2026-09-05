#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Error: database file argument is required.\n";
        return (1);
    }
    try
    {
        BitcoinExchange bitcoin;

        bitcoin.loadDatabase("data.csv");
        bitcoin.inputDatabase(argv[1]);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return (0);
}