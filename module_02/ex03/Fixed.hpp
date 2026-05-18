#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int fixed_point;
        static const int fractional_bits = 8;
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed &other);
        Fixed &operator=(const Fixed &other);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        Fixed(const int num);
        Fixed(const float num);
        float toFloat(void) const;
        int toInt(void) const;

        // comparison operators
        bool operator>(const Fixed &other) const;
        bool operator<(const Fixed &other) const;
        bool operator>=(const Fixed &other) const;
        bool operator<=(const Fixed &other) const;
        bool operator==(const Fixed &other) const;
        bool operator!=(const Fixed &other) const;

        // arithmetic operators
        Fixed operator+(const Fixed &other) const;
        Fixed operator-(const Fixed &other) const;
        Fixed operator*(const Fixed &other) const;
        Fixed operator/(const Fixed &other) const;

        // increment and decrement operators
        Fixed &operator++(); // prefix increment
        Fixed operator++(int); // postfix increment
        Fixed &operator--(); // prefix decrement
        Fixed operator--(int); // postfix decrement

        // overloaded member functions
        static Fixed &min(Fixed &x, Fixed &y);
        static Fixed &max(Fixed &x, Fixed &y);
        static const Fixed &min(const Fixed &x, const Fixed &y);
        static const Fixed &max(const Fixed &x, const Fixed &y);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif