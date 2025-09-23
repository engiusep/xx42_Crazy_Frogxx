#include "HumanA.hpp"




HumanA::HumanA(std::string const & name, Weapon & weapon) : _name(name), _weapon(weapon) {}
HumanA::~HumanA()
{
}

void HumanA::attack()
{
    std::cout << _name << " " <<  _weapon.getType() << std::endl;
}


