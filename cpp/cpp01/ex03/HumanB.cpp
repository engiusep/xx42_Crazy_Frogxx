#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {}


void    HumanB::setWeapon(Weapon& weapon)
{
    _weapon = &weapon;
}
HumanB::~HumanB()
{
}
void HumanB::attack()
{
    std::cout << _name << " " <<  _weapon->getType() << std::endl;
}