#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include <iostream>



int main()
{
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    const WrongAnimal* wrong = new WrongAnimal();
    const WrongAnimal* wrongcat = new WrongCat();

    std::cout << wrongcat->getType() << " " << std::endl;
    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;

    wrong->makeSound();
    wrongcat->makeSound();
    cat->makeSound();
    dog->makeSound();
    meta->makeSound();
    
    delete meta;
    delete dog;
    delete cat;
    delete wrong;
    delete wrongcat;
   return 0;
}