#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


int main()
{
    //Animal  *animal = new Animal();
    Animal *cat = new Cat();
    Animal *dog = new Dog();
    
    delete cat;
    delete dog;
}