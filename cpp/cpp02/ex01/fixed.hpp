#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream> 
#include <cmath>

class Fixed
{
    private:
        int _value;
        static const int _fractionalBits  = 8;
    public:
        Fixed();
        ~Fixed();
        Fixed(const int nb);
        Fixed(const float nb);
        Fixed(const Fixed &cpy);
        void    setRawBits(const int raw);
        int     getRawBits(void) const;
        float toFloat(void) const;
        int toInt( void ) const;
        Fixed &operator=(const Fixed &rhs);
};

std::ostream &operator<<(std::ostream &out, const Fixed &f);



#endif