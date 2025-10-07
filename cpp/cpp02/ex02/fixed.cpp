#include "fixed.hpp"
#include <cmath>

Fixed::Fixed(void) 
{
    _rawBits = 0;
}

Fixed::Fixed(int const n) {
    _rawBits = n << _fractionalBits;
}

Fixed::Fixed(float const f) 
{
    _rawBits = roundf(f * (1 << _fractionalBits));
}

Fixed::Fixed(Fixed const & src) {
    *this = src;
}

Fixed::~Fixed() {}

Fixed& Fixed::operator=(Fixed const & rhs) 
{
    if (this != &rhs)
        this->_rawBits = rhs.getRawBits();
    return *this;
}


bool Fixed::operator>(Fixed const & rhs) const 
{
    return this->getRawBits() > rhs.getRawBits();
}

bool Fixed::operator<(Fixed const & rhs) const 
{
    return this->getRawBits() < rhs.getRawBits();
}

bool Fixed::operator<=(Fixed const & rhs) const 
{
    return this->getRawBits() <= rhs.getRawBits();
}

bool Fixed::operator>=(Fixed const & rhs) const {
    return this->getRawBits() >= rhs.getRawBits();
}

bool Fixed::operator==(Fixed const & rhs) const {
    return this->getRawBits() == rhs.getRawBits();
}

bool Fixed::operator!=(Fixed const & rhs) const 
{
    return this->getRawBits() != rhs.getRawBits();
}


int Fixed::getRawBits(void) const 
{
    return _rawBits;
}


Fixed Fixed::operator+(Fixed const & rhs) const 
{
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(Fixed const & rhs) const 
{
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const & rhs) const 
{
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const & rhs) const 
{
    return Fixed(this->toFloat() / rhs.toFloat());
}


Fixed& Fixed::operator++() 
{
    ++_rawBits;
    return *this;
}

Fixed& Fixed::operator--() 
{
    --_rawBits;
    return *this;
}


Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    _rawBits++;
    return tmp;
}

Fixed Fixed::operator--(int) 
{
    Fixed tmp(*this);
    _rawBits--;
    return tmp;
}


void Fixed::setRawBits(int const raw) 
{
    std::cout << "setRawBits member function called" << std::endl;
    _rawBits = raw;
}


int Fixed::toInt(void) const 
{
    return _rawBits >> _fractionalBits;
}


float Fixed::toFloat(void) const 
{
    return (float)_rawBits / (1 << _fractionalBits);
}


std::ostream & operator<<(std::ostream & other, Fixed const & rhs)
{
    other << rhs.toFloat();
    return other;
}

Fixed const& Fixed::min(Fixed const & f1, Fixed const & f2) 
{
    if (f1 < f2)
        return f1;
    else
        return f2;
}

Fixed const& Fixed::max(Fixed const & f1, Fixed const & f2) 
{
    if (f1 > f2)
        return f1;
    else
        return f2;
}

Fixed& Fixed::min(Fixed & f1, Fixed & f2) 
{
    if (f1 < f2)
        return f1;
    else
        return f2;
}

Fixed& Fixed::max(Fixed & f1, Fixed & f2)
{
    if (f1 > f2)
        return f1;
    else
        return f2;
}
