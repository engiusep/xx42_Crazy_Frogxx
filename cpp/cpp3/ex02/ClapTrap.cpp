#include "ClapTrap.hpp"



ClapTrap::ClapTrap()
{
    std::cout << "constructor call CLAP" << std::endl;
    std::cout << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _HitPoint(100) ,_EnergiePoints (50) , _AttackDamage(20)
{
    std::cout << "constructor name call CLAP " << _name <<std::endl;
    std::cout << std::endl;
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
    std::cout << "destructor call" << std::endl;
    std::cout << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if(_EnergiePoints <= 0)
    {
        std::cout << "no energie" << std::endl;
    }
    else if(_HitPoint <= 0)
    {
        std::cout << _name << "is die" << std::endl;
    }
    else
    {
        std::cout << _name << " attacks " << target << " causing " << _AttackDamage << " points of damage!" << std::endl;
        _EnergiePoints--;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    _HitPoint -= amount;
    if(_HitPoint <= 0)
    {
        std::cout << _name << "die" << std::endl;
    }
    else if(_HitPoint <= 0)
    {
        std::cout << _name << "is die" << std::endl;
    }
    else
        std::cout << _name << "after attack have = " << _HitPoint << "HP" << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if(_EnergiePoints <= 0)
    {
        std::cout << "No energie for repair" << std::endl;
    }
    else
    {
        std::cout << "Repaired at " << amount << std::endl;
        _HitPoint += amount;
        std::cout << "Hit point = " << _HitPoint << std::endl;  
    }
}
const std::string ClapTrap::getName() const
{
    return _name;
} 
int ClapTrap::getAttack() const
{
    return _AttackDamage;
}  