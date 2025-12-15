#include "Cat.hpp"



Cat::Cat() : Animal()
{
    _type = "Cat";
    _brain = new Brain();
    std::cout << "Cat constructor" << std::endl;
}

Cat::Cat(Cat const & src) : Animal(src), _brain(new Brain(*src._brain)) 
{
    std::cout << "Dog copy constructor called" << std::endl;
}

Cat& Cat::operator=(Cat const & rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        Animal::operator=(rhs);
        Brain* newBrain = new Brain(*rhs._brain);
        delete _brain;
        _brain = newBrain;
    }
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
