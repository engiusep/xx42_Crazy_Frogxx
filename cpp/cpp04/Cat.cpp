#include "Animal.hpp"



Cat::Cat()
{
    _type = "Cat";
    std::cout << "Cat constructor" << std::endl;
}

Cat::Cat(const Cat &cpy)
{
    if(this != &cpy)
        this->_type = cpy._type;
}

Cat &Cat::operator=(const Cat &rhs)
{
    Animal::operator=(rhs);
    return *this;
}

void Cat::makeSound(void) const
{
    std::cout << "Miaou" << std::endl;
}
Cat::~Cat()
{
    std::cout << "Cat destructor" << std::endl;
}