
#include "Zombie.hpp"



int main()
{
    Zombie *zombie = newZombie();
    randomChump("Nassim");
    zombie->annouce();
    delete zombie;
    return (0);
}