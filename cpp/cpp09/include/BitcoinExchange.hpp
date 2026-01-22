#ifndef BITCOIN_EXCHANGE
#define BITCOIN_EXCHANGE
#include <iostream>
#include <map>
#include <fstream>

class BitcoinExchange
{
    private:
        std::map<std::string,double> _mapData;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        
        BitcoinExchange(BitcoinExchange const & src);
        BitcoinExchange &operator=(BitcoinExchange const & rhs);

        void loadDataBase(std::string const &data);
        void processInputFile(std::string const &filename);

};



#endif