#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include "Brain.hpp"



class Animal
{
    protected:
        Animal();
        std::string _type;
    public:
        Animal(const Animal &cpy);
        Animal &operator=(const Animal &rhs);
        virtual void    makeSound(void) const = 0;
        virtual ~Animal();
    
};

#endif