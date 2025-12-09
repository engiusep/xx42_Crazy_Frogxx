#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    FragTrap JimFrag("Jim");
    ScavTrap HugoScav("Hugo");
    ScavTrap PaulScav("Paul");
    ClapTrap RemyClap("Remy");

    RemyClap.attack(JimFrag.getName());
    JimFrag.takeDamage(RemyClap.getAttack());
    std::cout << std::endl;
    JimFrag.highFivesGuys();
    std::cout << std::endl;
    PaulScav.guardGate();
    std::cout << std::endl;
    HugoScav.attack(JimFrag.getName());
    JimFrag.beRepaired(10);
    std::cout << std::endl;
    HugoScav.guardGate();
    return 0;
}