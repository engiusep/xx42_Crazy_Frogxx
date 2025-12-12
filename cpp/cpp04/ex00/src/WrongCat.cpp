#include "../include/WrongCat.hpp"


WrongCat::WrongCat()
{
    _type = " Wrong CAT";
    std::cout << "Wrong cat constructor" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "DESTRUCOUR WRONG CAT" << std::endl;
}
void WrongCat::makeSound() const
{
    std::cout << "Wrong wouf wouf" << std::endl;
}
WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
    WrongAnimal::operator=(rhs);
    return *this;
}
WrongCat::WrongCat(const WrongCat &cpy)
{
    if(this != &cpy)
        this->_type = cpy._type;
}
