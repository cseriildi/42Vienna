#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(float a, float b);
		Point(const Point& other);
		~Point();
		Point&	operator=(const Point& other);

		//getters
		Fixed get_x() const;
		Fixed get_y() const;
		
	private:
		
		Fixed const _x; //NOLINT
		Fixed const _y; //NOLINT
};

bool bsp(Point a, Point b, Point c, Point point);

#endif
