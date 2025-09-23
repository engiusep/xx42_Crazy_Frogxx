#include "Zombie.hpp"

Zombie::Zombie() :_name("Default"){}

void Zombie::setName(std::string name)  
{
    _name = name;
}

Zombie::~Zombie(){}

void    Zombie::announce()
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}