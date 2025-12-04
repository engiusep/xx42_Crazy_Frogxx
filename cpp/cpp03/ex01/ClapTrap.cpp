#include "ClapTrap.hpp"



ClapTrap::ClapTrap()
{
    std::cout << "constructor call ClapTrap" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _HitPoint(100) ,_EnergiePoints (50) , _AttackDamage(20)
{
    std::cout << "constructor name call ClapTrap " << _name <<std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &cpy)
{
    std::cout << "Constructor copy call" << std::endl;
    if(this != &cpy)
    {
        this->_AttackDamage = cpy._AttackDamage;
        this->_EnergiePoints = cpy._EnergiePoints;
        this->_HitPoint = cpy._HitPoint;
    }
}
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if(this != &other)
        *this = other;
    std::cout << "surcharge call" << std::endl;
    return *this;
}
ClapTrap::~ClapTrap()
{
    std::cout << "destructor ClapTrap call " << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if(_EnergiePoints <= 0)
    {
        std::cout << "no energie tete noeil" << std::endl;
    }
    else
    {
        std::cout << _name << " attacks " << target << " causing " << _AttackDamage << " points of damage!" << std::endl;
        _EnergiePoints--;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    (void)amount;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    (void)amount;
}
std::string ClapTrap::getName() const
{
    return _name;
}  