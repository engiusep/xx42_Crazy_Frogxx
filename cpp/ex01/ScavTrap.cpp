#include "ScavTrap.hpp"


ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap noname" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap constructor call" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "destructor ScavTrap " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &cpy)
{
    if(this != &cpy)
    {
        this->_AttackDamage = cpy._AttackDamage;
        this->_EnergiePoints = cpy._EnergiePoints;
        this->_HitPoint = cpy._HitPoint;
        this->_name = cpy._name;
    }
}
ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
    if(this != &rhs)
    {
        ClapTrap::operator=(rhs);
    }
    return *this;
}

void ScavTrap::guardGate()
{
    std::cout << _name <<" is now in Gate keeper mode." << std::endl;
}
