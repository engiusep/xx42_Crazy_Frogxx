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
        std::string getType() const;
        virtual void    setIdea(int index,std::string idea) = 0;
        virtual std::string getIdea(int index) = 0;
        virtual void print() = 0;
        virtual ~Animal();
    
};

class Cat : public Animal
{
    private:
        Brain *_brain;
    public:
        Cat();
        Cat(const Cat &cpy);
        Cat &operator=(const Cat &rhs);
        void    makeSound(void) const;
        std::string getIdea(int index);
        void setIdea(int index,std::string idea);
        void  print();
        ~Cat();

        
};

class Dog : public Animal
{
    private:
        Brain *_brain;
    public:
        Dog();
        Dog(const Dog &cpy);
        Dog &operator=(const Dog &rhs);
        void    makeSound(void) const;
        std::string getIdea(int index);
        void setIdea(int index,std::string idea);
        void  print();
        ~Dog();
};



#endif