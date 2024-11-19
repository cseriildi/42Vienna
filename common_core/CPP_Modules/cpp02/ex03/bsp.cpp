//NOLINTBEGIN(bugprone-easily-swappable-parameters)

#include "Point.hpp"
#include "Fixed.hpp"

float	cross_product(Point const& a, Point const& b, Point const& p)
{
	float const ax = a.get_x().toFloat();
	float const ay = a.get_y().toFloat();
	float const bx = b.get_x().toFloat();
	float const by = b.get_y().toFloat();
	float const px = p.get_x().toFloat();
	float const py = p.get_y().toFloat();

	return (bx - ax) * (py - ay) - (by - ay) * (px - ax);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) // NOLINT(performance-unnecessary-value-param)
{
	float const abp = cross_product(a, b, point);
	float const bcp = cross_product(b, c, point);
	float const cap = cross_product(c, a, point);

	return (abp > 0 && bcp > 0 && cap > 0) || (abp < 0 && bcp < 0 && cap < 0);
}

//NOLINTEND(bugprone-easily-swappable-parameters)
