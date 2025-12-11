#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat &operator=(const WrongCat &rhs);
        WrongCat(const WrongCat &cpy);
        ~WrongCat();
        void makeSound() const;
};

#endif