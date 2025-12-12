#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

class Animal
{
    protected:
        std::string _type;
    public:
        Animal();
        Animal(std::string type);
        Animal(const Animal &cpy);
        Animal &operator=(const Animal &rhs);

        std::string getType() const;

        virtual void    makeSound(void) const;
        virtual ~Animal();
};
#endif