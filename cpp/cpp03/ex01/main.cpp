#include "ClapTrap.hpp"

int main()
{
    ScavTrap b("Hugo");
    ScavTrap trap("Trap");
    trap.guardGate();
    b.attack("raymond");
    b.guardGate();
    return 0;
}