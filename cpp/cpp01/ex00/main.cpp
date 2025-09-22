
#include "Zombie.hpp"



int main()
{
    Zombie *zombie = newZombie("Yannis");

    randomChump("Hugo");
    zombie->annouce();
    delete zombie;
    return (0);
}