#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::~Point() {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point &Point::operator=(const Point &other)
{
    if (this != &other)
        return *this;
    return *this;
}

Point::Point(const float x, const float y) : x(x), y(y) {}

Fixed Point::getX(void) const
{
    return this->x;
}

Fixed Point::getY(void) const
{
    return this->y;
}
