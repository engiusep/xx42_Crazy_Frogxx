#include "../include/Animal.hpp"


Animal::Animal()
{
    std::cout << "all Animal construcor" << std::endl;
}
Animal::Animal(std::string type) : _type(type) {}

std::string Animal::getType() const
{
    return this->_type;
} 
Animal::Animal(const Animal &cpy)
{
    this->_type = cpy._type;
}

Animal &Animal::operator=(const Animal &rhs)
{
    if(this != &rhs)
        *this = rhs;
    return *this;
}
void Animal::makeSound(void) const
{
    std::cout << "ANIMAL" << std::endl;
}
Animal::~Animal()
{
    std::cout << "Animal destructor" << std::endl;
}