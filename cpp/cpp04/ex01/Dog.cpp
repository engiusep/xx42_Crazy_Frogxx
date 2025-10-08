#include "Animal.hpp"



Dog::Dog()
{
    _brain = new Brain();
    _type = "Dog";
    std::cout << "Dog constructor" << std::endl;
}

Dog::Dog(const Dog &cpy)
{
    if(this != &cpy)
        this->_type = cpy._type;
}

Dog &Dog::operator=(const Dog &rhs)
{
    Animal::operator=(rhs);
    return *this;
}

void Dog::makeSound(void) const
{
    std::cout << "Wouf" << std::endl;
}
Dog::~Dog()
{
    delete _brain;
    std::cout << "Dog destructor" << std::endl;
}
void    Dog::setIdea(int index,std::string idea)
{
    _ideas[index] = idea;
}

std::string Dog::getIdea(int index)
{
   return _ideas[index];
}