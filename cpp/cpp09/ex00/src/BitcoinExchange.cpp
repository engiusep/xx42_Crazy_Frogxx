#include "../include/BitcoinExchange.hpp"


bool isValidDate(const std::string& date) 
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year  = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day   = std::atoi(date.substr(8, 2).c_str());

    if (year < 2000 || year > 2026 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (year % 4 == 0) {
        daysInMonth[2] = 29;
    }

    return day <= daysInMonth[month];
}

BitcoinExchange::BitcoinExchange() {} ;
BitcoinExchange::~BitcoinExchange() {};

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs) 
{
    if (this != &rhs) 
    {
        _mapData = rhs._mapData;
    }
    return *this;
}
BitcoinExchange::BitcoinExchange(BitcoinExchange const & src) 
{
    *this = src;
}



void BitcoinExchange::loadDataBase(std::string const &data)
{

    std::ifstream file(data.c_str());
    if(!file)
    {
        std::cout << "Error open file" << std::endl;
        return;
    
    }

    std::string line;
    getline(file,line);

    while (getline(file,line))
    {
        size_t pos = line.find(',');
        std::string date = line.substr(0,pos);

        double price = atof(line.substr(pos + 1).c_str());
        _mapData[date] = price;
    }
    file.close();
} 


void BitcoinExchange::processInputFile(std::string const &filename) 
{
    std::ifstream file(filename.c_str());
    if (!file.is_open()) 
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) 
    {
        size_t sep = line.find(" | ");
        
        if (sep == std::string::npos) 
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, sep);
        std::string valueStr = line.substr(sep + 3);
        if (!isValidDate(date)) 
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        char* endPtr;
        double value = std::strtod(valueStr.c_str(), &endPtr);
        
        if (*endPtr != '\0' && !isspace(*endPtr)) 
        {
            std::cerr << "Error: bad input => " << valueStr << std::endl;
            continue;
        }
        if (value < 0) 
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000) 
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        std::map<std::string, double>::iterator it = _mapData.lower_bound(date);

        if (it == _mapData.end() || it->first != date) 
        {
            if (it == _mapData.begin()) 
            {
                std::cerr << "Error: date too early => " << date << std::endl;
                continue;
            }
            --it;
        }
        std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
    }
}