#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>



class ClapTrap
{
    private:
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

#endif