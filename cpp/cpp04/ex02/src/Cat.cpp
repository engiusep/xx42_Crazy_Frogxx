#include "Cat.hpp"



Cat::Cat()
{
    _brain = new Brain();
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
    delete _brain;
    std::cout << "Cat destructor" << std::endl;
}
