#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name){}
Zombie::~Zombie()
{
    std::cout << _name << " Zombie has been destroy ☠️🧟☠️" << std::endl;
}

void Zombie::annouce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}