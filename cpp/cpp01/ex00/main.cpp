
#include "Zombie.hpp"



int main()
{
    Zombie *zombie = newZombie("Yannis");
    randomChump("Nassim");
    zombie->annouce();
    delete zombie;
    return (0);
}