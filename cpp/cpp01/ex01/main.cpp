#include "Zombie.hpp"



int main()
{
    int n;
    n = 10;
    Zombie* zombie;

    zombie = zombieHorde(n,"Yannis");
    zombie->announce();
    zombie[4].announce();

    delete [] zombie;
}