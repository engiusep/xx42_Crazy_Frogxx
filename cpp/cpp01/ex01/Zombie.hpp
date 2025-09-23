#include <iostream>


class Zombie
{
    private:
        std::string _name;
    public:
        int nb_zombie;
        Zombie();
        Zombie(std::string name);
        ~Zombie();
        void    announce();
        void    setName(std::string name);

};

Zombie* zombieHorde(int N, std::string name);