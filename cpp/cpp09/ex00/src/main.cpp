#include "../include/BitcoinExchange.hpp"
#include <iostream>

int main(int argc,char **argv)
{
    (void)argv;
    if(argc != 2)
    {
        std::cout << "Error Usage : ./btc input.txt" << std::endl;
        return 1; 
    }
    (void)argc;
    BitcoinExchange btc;

    btc.loadDataBase("data.csv");

    btc.processInputFile(argv[1]);
}