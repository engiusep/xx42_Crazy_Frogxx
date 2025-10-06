#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:

        int                 _rawBits;
        static const int    _fractionalBits = 8; 
        
    public:
        Fixed( void );
        Fixed( int const n );
        Fixed( float const f );
        Fixed( Fixed const & src );
        ~Fixed( void );
        
        // affectation
        Fixed& operator=(Fixed const & rhs);
        
        // comparaison
        bool operator>(Fixed const & rhs) const;
        bool operator<(Fixed const & rhs) const;
        bool operator<=(Fixed const & rhs) const;
        bool operator>=(Fixed const & rhs) const;
        bool operator==(Fixed const & rhs) const;
        bool operator!=(Fixed const & rhs) const;

        // arithmetique
        Fixed operator+(Fixed const & rhs) const;
        Fixed operator-(Fixed const & rhs) const;
        Fixed operator*(Fixed const & rhs) const;
        Fixed operator/(Fixed const & rhs) const;
        
        // incrémentation
        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);

        int  getRawBits( void ) const;
        void setRawBits( int const raw );
        int toInt( void ) const;
        float toFloat( void ) const;

        static Fixed& min(Fixed & f1, Fixed & f2);
        static Fixed& max(Fixed & f1, Fixed & f2);
        static Fixed const & min(Fixed const & f1, Fixed const & f2);
        static Fixed const & max(Fixed const & f1, Fixed const & f2);
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif