//NOLINTBEGIN(bugprone-easily-swappable-parameters)

#include "Point.hpp"
#include "Fixed.hpp"

Fixed	cross_product(Point const& a, Point const& b, Point const& p)
{
	Fixed const ax = a.get_x();
	Fixed const ay = a.get_y();
	Fixed const bx = b.get_x();
	Fixed const by = b.get_y();
	Fixed const px = p.get_x();
	Fixed const py = p.get_y();

	return (bx - ax) * (py - ay) - (by - ay) * (px - ax);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) // NOLINT(performance-unnecessary-value-param)
{
	Fixed const abp = cross_product(a, b, point);
	Fixed const bcp = cross_product(b, c, point);
	Fixed const cap = cross_product(c, a, point);

	return (abp > 0 && bcp > 0 && cap > 0) || (abp < 0 && bcp < 0 && cap < 0);
}

//NOLINTEND(bugprone-easily-swappable-parameters)
