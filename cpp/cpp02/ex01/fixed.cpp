#include "fixed.hpp"




Fixed::Fixed() 
{
    _value = 0;
    std::cout << "constructor call" << std::endl;
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
Fixed &Fixed::operator=(const Fixed &rhs)
{
    if(this != &rhs)
    {
        this->_value = rhs.getRawBits();
    }
    std::cout << "surcharge call" << std::endl;
    return *this;
}

Fixed::Fixed(const int nb)
{
    _value = nb << _fractionalBits; 
    std::cout << "Constructor integer call" << std::endl;
}

Fixed::Fixed(const float nb)
{
    _value = roundf(nb * (1 << _fractionalBits)); 
    std::cout << "Constructor float call" << std::endl;
}
std::ostream &operator<<(std::ostream &out, const Fixed &f) 
{
    out << f.toFloat(); 
    return out;
}

float Fixed::toFloat(void) const
{
    return (float)_value / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
    return _value >> _fractionalBits;
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