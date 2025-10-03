#ifndef FIXED_HPP
#define FIXED_HPP



class Fixed
{
    private:
        int _value;
        static const int fracOfBit = 8;
    public:
        Fixed();
        Fixed(const Fixed &cpy);
        Fixed &operator=(const Fixed &other);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        ~Fixed();
};


#endif