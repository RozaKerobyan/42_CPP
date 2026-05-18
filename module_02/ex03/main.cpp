#include "Point.hpp"

int	main(void)
{
	Point	a(0, 0);
	Point	b(10, 0);
	Point	c(0, 10);

	Point	p1(2, 2);
    Point   p2(20, 20);
    Point   p3(0, 0);


    std::cout << "Test 1:\n";
    std::cout << "A(" << a.getX() << ", " << a.getY() << "), "
    << "B(" << b.getX() << ", " << b.getY() << "), "
    << "C(" << c.getX() << ", " << c.getY() << "), "
    << "P(" << p1.getX() << ", " << p1.getY() << ")\n";
	if (bsp(a, b, c, p1))
		std::cout << "P point is Inside in the triangle\n";
	else
		std::cout << "P point is Outside the triangle\n";

    std::cout << "\nTest 2:\n";
    std::cout << "A(" << a.getX() << ", " << a.getY() << "), "
    << "B(" << b.getX() << ", " << b.getY() << "), "
    << "C(" << c.getX() << ", " << c.getY() << "), "
    << "P(" << p2.getX() << ", " << p2.getY() << ")\n";
    if (bsp(a, b, c, p2))
        std::cout << "P point is Inside in the triangle\n";
    else
        std::cout << "P point is Outside the triangle\n";

    std::cout << "\nTest 3:\n";
    std::cout << "A(" << a.getX() << ", " << a.getY() << "), "
    << "B(" << b.getX() << ", " << b.getY() << "), "
    << "C(" << c.getX() << ", " << c.getY() << "), "
    << "P(" << p3.getX() << ", " << p3.getY() << ")\n";
    if (bsp(a, b, c, p3))
        std::cout << "P point is Inside in the triangle\n";
    else
        std::cout << "P point is Outside the triangle\n";
}