#include "ClapTrap.hpp"



ClapTrap::ClapTrap()
{
    std::cout << "constructor call" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _HitPoint(10) ,_EnergiePoints (10) , _AttackDamage(0)
{
    std::cout << "constructor name call" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &cpy)
{
    std::cout << "Constructor copy call" << std::endl;
    if(this != &cpy)
    {
        this->_AttackDamage = cpy._AttackDamage; // ou geteur;
        this->_EnergiePoints = cpy._EnergiePoints;
        this->_HitPoint = cpy._HitPoint;
    }
}
ClapTrap::~ClapTrap()
{
    std::cout << "destructor call" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if(_EnergiePoints <= 0)
    {
        std::cout << "no energie tete noeil" << std::endl;
    }
    std::cout << _name << " attacks " << target << " causing " << _AttackDamage << " points of damage!" << std::endl;
    _EnergiePoints--;
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
    std::cout << "get name call" << std::endl;
    return _name;
}  