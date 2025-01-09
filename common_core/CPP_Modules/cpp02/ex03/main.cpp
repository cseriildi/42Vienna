//NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)

#include <iostream>
#include "Point.hpp"

int main()
{
	{
		Point A(1, 1);
		Point B(4, 1);
		Point C(2.5, 4);

		Point insidePoint(2.5, 2);
		Point outsidePoint(0, 0);
		Point onEdgePoint(2.5, 1);
		Point vertexPoint(1, 1); 

		std::cout << "Triangle: A(" << A.get_x().toFloat() << ", " << A.get_y().toFloat() << "), ";
		std::cout << "B(" << B.get_x().toFloat() << ", " << B.get_y().toFloat() << "), ";
		std::cout << "C(" << C.get_x().toFloat() << ", " << C.get_y().toFloat() << ").\n";

		std::cout << "Point (2.5, 2) is " 
				<< (bsp(A, B, C, insidePoint) ? "inside" : "outside") 
				<< " the triangle.\n";

		std::cout << "Point (0, 0) is " 
				<< (bsp(A, B, C, outsidePoint) ? "inside" : "outside") 
				<< " the triangle.\n";

		std::cout << "Point (2.5, 1) is " 
				<< (bsp(A, B, C, onEdgePoint) ? "inside" : "outside") 
				<< " the triangle.\n";

		std::cout << "Point (1, 1) is " 
				<< (bsp(A, B, C, vertexPoint) ? "inside" : "outside") 
				<< " the triangle.\n";
	}
	{
	/* 
		float ax, ay, bx, by, cx, cy, px, py;

		std::cout << "Enter coordinates for point A (x y): ";
		std::cin >> ax >> ay;
		Point A(ax, ay);

		std::cout << "Enter coordinates for point B (x y): ";
		std::cin >> bx >> by;
		Point B(bx, by);

		std::cout << "Enter coordinates for point C (x y): ";
		std::cin >> cx >> cy;
		Point C(cx, cy);

		std::cout << "Enter coordinates for the point to check (x y): ";
		std::cin >> px >> py;
		Point point(px, py);

		std::cout << "Triangle: A(" << A.get_x().toFloat() << ", " << A.get_y().toFloat() << "), ";
		std::cout << "B(" << B.get_x().toFloat() << ", " << B.get_y().toFloat() << "), ";
		std::cout << "C(" << C.get_x().toFloat() << ", " << C.get_y().toFloat() << ").\n";

		std::cout << "Point (" << px << ", " << py << ") is " 
				<< (bsp(A, B, C, point) ? "inside" : "outside") 
				<< " the triangle.\n";
	 */
	} 
}

//NOLINTEND(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)
