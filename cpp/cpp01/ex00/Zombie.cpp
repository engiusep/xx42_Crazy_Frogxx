#include "Zombie.hpp"

// Zombie::Zombie()
// {

// }
Zombie::Zombie(std::string name) : _name(name){}
Zombie::~Zombie()
{
    std::cout << "Zombie has been destroy ☠️🧟☠️" << std::endl;
}

void Zombie::annouce(void)
{
    std::cout << _name << std::endl;
}