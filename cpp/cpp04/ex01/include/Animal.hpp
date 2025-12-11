#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include "Brain.hpp"



class Animal
{
    protected:
        std::string _type;
    public:
        Animal();
        Animal(const Animal &cpy);
        Animal &operator=(const Animal &rhs);
        virtual void    makeSound(void) const;

        virtual ~Animal();
    
};

#endif