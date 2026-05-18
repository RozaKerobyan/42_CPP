#include "Point.hpp"

float	area(Point const a, Point const b, Point const c)
{
	return (
		(
			a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())
			+ b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat())
			+ c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())
		) / 2.0f
	);
}

bool	bsp(Point const a, Point const b,
			Point const c, Point const point)
{
	float	abc;
	float	pab;
	float	pbc;
	float	pca;

	abc = fabs(area(a, b, c));
	pab = fabs(area(point, a, b));
	pbc = fabs(area(point, b, c));
	pca = fabs(area(point, c, a));

	if (pab == 0 || pbc == 0 || pca == 0)
		return (false);

	return ((pab + pbc + pca) == abc);
}
