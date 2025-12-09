#include "Animal.hpp"
#include "Brain.hpp"


int main()
{
    //Animal  *animal = new Animal();
    Animal *cat = new Cat();
    Animal *dog = new Dog();

    dog->setIdea(99,"chien manger");
    cat->setIdea(12,"dormir");
    //cat->getIdea(12);
    cat->print();
    dog->print();
    delete cat;
    delete dog;
}