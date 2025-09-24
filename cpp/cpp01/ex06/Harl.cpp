#include "Harl.hpp"

Harl::Harl(){}
Harl::~Harl(){}

void    Harl::_debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "debug crazy" << std::endl;
}

void    Harl::_info(void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "info crazy" << std::endl;
}
void Harl::_warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "warning crazy" << std::endl;
}
void    Harl::_error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "error crazy" << std::endl;
}

void   Harl::complain(std::string level)
{
    size_t i = 0;
    std::string tab[] = {"DEBUG","INFO","WARNING","ERROR"};
    
    while(i < 4)
    {   
        if(level == tab[i])
            break;
        i++;
    }

    switch (i)
    {
        case 0:
            _debug();    
        case 1:
            _info();
        case 2:
            _warning();
        case 3:
            _error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            
    }
}
