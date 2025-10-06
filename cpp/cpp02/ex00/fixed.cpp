#include "fixed.hpp"
#include <iostream>



Fixed::Fixed()
{
    _value = 0;
    std::cout << "Constructor call" << :: std::endl;
}
Fixed::~Fixed()
{
    std::cout << "destructor call" << std::endl;
}

Fixed::Fixed(const Fixed &cpy)
{
    std::cout << "constructor cpy call" << std::endl;
    _value = cpy._value;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if(_value != other._value)
    {
        this->_value = other._value;
    }
    std::cout << "surcharge call" << std::endl;
    return *this;
}
void Fixed::setRawBits(int const raw)
{
    _value = raw;
}

int Fixed::getRawBits(void) const
{
    std::cout << "get raw bit call" << std::endl;
    return _value;
}