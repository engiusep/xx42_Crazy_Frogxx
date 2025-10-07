#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>



class ClapTrap
{
    protected:
        std::string _name;
        int _HitPoint;
        int _EnergiePoints;
        int _AttackDamage;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap &operator=(const ClapTrap &other);
        ClapTrap(const ClapTrap &cpy);
        ~ClapTrap();
        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        std::string   getName(void) const;

};

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap &operator=(const ScavTrap &rhs);
        ScavTrap(const ScavTrap &cpy);
        ~ScavTrap();
        void    guardGate();

};

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap &operator=(const FragTrap &rhs);
        FragTrap(const FragTrap &cpy);
        void highFivesGuys(void);
        ~FragTrap();
};

#endif