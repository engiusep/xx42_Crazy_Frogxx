#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

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

#endif