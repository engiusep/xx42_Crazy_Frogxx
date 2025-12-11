#include "Dog.hpp"

Dog::Dog()
{
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
    std::cout << "Dog destructor" << std::endl;
}