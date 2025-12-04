#include "ClapTrap.hpp"


FragTrap::FragTrap()
{
    std::cout << "constructor FragTrap no name" << std::endl;
    std::cout << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "constructor FragTrap whit name" << std::endl;
    std::cout << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
    if(this != &rhs)
    {
        ClapTrap::operator=(rhs);
    }
    return *this;
}

FragTrap::FragTrap(const FragTrap &cpy)
{
    if(this != &cpy)
    {
        this->_AttackDamage = cpy._AttackDamage;
        this->_EnergiePoints = cpy._EnergiePoints;
        this->_HitPoint = cpy._HitPoint;
        this->_name = cpy._name;
    }
}
void FragTrap::highFivesGuys()
{
    std::cout << _name << " say High Five Guys !" << std::endl;
}
FragTrap::~FragTrap()
{
    std::cout << "Destrucor FragTrap call " << _name << std::endl;
    std::cout << std::endl;
}
