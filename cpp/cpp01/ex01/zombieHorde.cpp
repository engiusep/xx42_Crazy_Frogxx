#include "Zombie.hpp"


Zombie* zombieHorde(int N,std::string name)
{
    int i;
    i = 0;

    Zombie* zombie = new Zombie[N];
    while(i < N)
    {
        if(i == 4)
        {
            zombie[i].setName("Nassim");
            i++;
            continue;
        }
        zombie[i].setName(name);
        i++;
    }
    return zombie;
}