#include "Animal.hpp"
#include "Brain.hpp"


int main()
{
    Animal *cat = new Cat();
    cat->setIdea(12,"dormir");
    std::cout << cat->getIdea(12) << std::endl;
    cat->print();
}