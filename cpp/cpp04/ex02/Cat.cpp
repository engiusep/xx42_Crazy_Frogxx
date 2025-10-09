#include "Animal.hpp"



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
void    Cat::setIdea(int index,std::string idea)
{
    _brain->setIdea(index,idea);
}

std::string Cat::getIdea(int index)
{
   return  _brain->getIdea(index);
  
}

void Cat::print()
{
    for(int i = 0;i < 100;i++)
        std::cout << _brain->getIdea(i) << std::endl;
}