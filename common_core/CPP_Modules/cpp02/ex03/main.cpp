//NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)

#include <iostream>
#include "Point.hpp"

int main()
{
    Point A(1, 1);
    Point B(4, 1);
    Point C(2.5, 4);

    Point insidePoint(2.5, 2);
    Point outsidePoint(0, 0);
    Point onEdgePoint(2.5, 1);
    Point vertexPoint(1, 1); 

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

    return 0;
}

//NOLINTEND(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)
