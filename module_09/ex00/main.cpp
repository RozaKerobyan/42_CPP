#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Error: database file argument is required.\n";
        return (1);
    }
    BitcoinExchange bitcoin;
    bitcoin.loadDatabase("data.csv");
    bitcoin.inputDatabase(argv[1]);
    return (0);
}