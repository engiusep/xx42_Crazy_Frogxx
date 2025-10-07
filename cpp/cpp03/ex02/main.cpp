#include "ClapTrap.hpp"

int main()
{
    FragTrap five("Jim");
    ScavTrap b("Hugo");
    ScavTrap trap("Trap");
    five.highFivesGuys();
    trap.guardGate();
    b.attack("raymond");
    b.guardGate();
    return 0;
}