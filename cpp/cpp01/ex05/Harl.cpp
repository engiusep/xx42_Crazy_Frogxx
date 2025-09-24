#include "Harl.hpp"

Harl::Harl(){}
Harl::~Harl(){}

void    Harl::debug(void)
{
    std::cout << "debug crazy" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "info crazy" << std::endl;
}
void Harl::warning(void)
{
    std::cout << "warning crazy" << std::endl;
}
void    Harl::error(void)
{
    std::cout << "error crazy" << std::endl;
}

void   Harl::complain(std::string level)
{
    void (Harl::*fonction[])(void) = {&Harl::debug,&Harl::info,&Harl::warning,&Harl::error};
    std::string tab[] = {"DEBUG","INFO","WARNING","ERROR"};
    for(int i = 0; i < 4; i++)
    {
        if(level == tab[i])
            (this->*fonction[i])();
    }
}


