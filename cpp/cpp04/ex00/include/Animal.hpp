#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>



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