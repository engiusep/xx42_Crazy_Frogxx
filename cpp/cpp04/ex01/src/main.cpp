#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


int main()
{
    Animal* animal[10];

    for(int i = 0; i < 5; i++)
        animal[i] = new Dog();

    for(int i = 5; i < 10 ; i++)
        animal[i] = new Cat();

    for(int i = 0; i < 10;i++)
        animal[i]->makeSound();
    Dog basic;
    {
        Dog tmp = basic;
    }
    for(int i = 0; i < 10; i++)
        delete animal[i];
}