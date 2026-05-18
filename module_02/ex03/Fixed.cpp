#include "Fixed.hpp"

Fixed::Fixed()
{
    fixed_point = 0;
}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
}

Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        this->setRawBits(other.getRawBits());
    return *this;
}

int	Fixed::getRawBits(void) const
{
	return(this->fixed_point);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixed_point = raw;
}

Fixed::Fixed(const int num)
{
    fixed_point = num << fractional_bits;
}

Fixed::Fixed(const float num)
{
    fixed_point = roundf(num * (1 << fractional_bits));
}

float Fixed::toFloat(void) const
{
    return ((float)fixed_point / (1 << fractional_bits));
}

int Fixed::toInt(void) const
{
    return (fixed_point >> fractional_bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}

// comparison operators

bool Fixed::operator>(const Fixed &other) const
{
    return (this->fixed_point > other.fixed_point);
}

bool Fixed::operator<(const Fixed &other) const
{
    return (this->fixed_point < other.fixed_point);
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (this->fixed_point >= other.fixed_point);
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (this->fixed_point <= other.fixed_point);
}

bool Fixed::operator==(const Fixed &other) const
{
    return (this->fixed_point == other.fixed_point);
}

bool Fixed::operator!=(const Fixed &other) const
{
    return (this->fixed_point != other.fixed_point);
}

// arithmetic operators

Fixed Fixed::operator+(const Fixed &other) const
{
    return(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
    return(this->toFloat() / other.toFloat());
}

// increment and decrement operators

Fixed &Fixed::operator++() // prefix increment
{
    ++this->fixed_point;
    return (*this);
}

Fixed &Fixed::operator--() // prefix decrement
{
    --this->fixed_point;
    return (*this);
}

Fixed Fixed::operator++(int) // post increment
{
    Fixed tmp(*this);
    ++this->fixed_point;
    return (tmp);
}

Fixed Fixed::operator--(int) // post decrement
{
    Fixed tmp(*this);
    --this->fixed_point;
    return (tmp);
}

// overloaded member functions

Fixed &Fixed::min(Fixed &x, Fixed &y)
{
    if (x > y)
        return (y);
    else
        return (x);
}

Fixed &Fixed::max(Fixed &x, Fixed &y)
{
    if (x > y)
        return (x);
    else
        return (y);
}

const Fixed &Fixed::min(const Fixed &x, const Fixed &y)
{
    if (x > y)
        return (y);
    else
        return (x);
}

const Fixed &Fixed::max(const Fixed &x, const Fixed &y)
{
    if (x > y)
        return (x);
    else
        return (y);
}