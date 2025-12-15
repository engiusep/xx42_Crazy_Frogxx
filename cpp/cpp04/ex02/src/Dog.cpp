#include "Dog.hpp"



Dog::Dog() : Animal()
{
    _type = "Dog";
    _brain = new Brain();
    std::cout << "Dog constructor" << std::endl;
}

Dog::Dog(Dog const & src) : Animal(src), _brain(new Brain(*src._brain)) 
{
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(Dog const & rhs) 
{
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
void Dog::makeSound(void) const
{
    std::cout << "Wouf" << std::endl;
}
Dog::~Dog()
{
    delete _brain;
    std::cout << "Dog destructor" << std::endl;
}

