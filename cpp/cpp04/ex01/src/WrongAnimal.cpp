#include "WrongAnimal.hpp"
#include <iostream>


WrongAnimal::WrongAnimal() 
{
    std::cout << "wrong animal construcor" << std::endl;
}
WrongAnimal::~WrongAnimal() {};

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs)
{
    if(this != &rhs)
        *this = rhs;
    return *this;
}
WrongAnimal::WrongAnimal(const WrongAnimal &cpy)
{
    if(this != &cpy)
        this->_type = cpy._type;
}


void WrongAnimal::makeSound() const
{
    std::cout << "Wrong animal sound" << std::endl;
}

