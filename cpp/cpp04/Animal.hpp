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
        std::string getType() const;
        ~Animal();
    
};

class Cat : public Animal
{
    public:
        Cat();
        Cat(const Cat &cpy);
        Cat &operator=(const Cat &rhs);
        void    makeSound(void) const;
        ~Cat();

        
};

class Dog : public Animal
{
    public:
        Dog();
        Dog(const Dog &cpy);
        Dog &operator=(const Dog &rhs);
        void    makeSound(void) const;
        ~Dog();

        
};




#endif