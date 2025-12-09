#include "ClapTrap.hpp"

int main()
{
    ScavTrap Hugo("Hugo");
    ScavTrap Paul("Paul");
    ClapTrap Liam("Liam");
    Paul.guardGate();
    Hugo.attack(Paul.getName());
    Hugo.guardGate();
    Liam.attack(Hugo.getName());
    return 0;
}