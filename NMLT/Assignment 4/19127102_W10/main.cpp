#include "function.h"

int main()
{
	point x, y;
	triangle coord;
	double area, perimeter;
	inputAPoint(x);
	outputAPoint(x);
	inputAPoint(y);
	std::cout << "distance : " << distance(x, y) << std::endl;
	std::cout << "Quadrant of Point : " << findQuadrantOFAPoint(y) << std::endl;
	inputTriangle(coord);
	outputTriangle(coord);
	findPerimeterAndArea(coord, area, perimeter);
	std::cout << "Perimeter of Triangle : " << perimeter << std::endl;
	std::cout << "Area of Triangle : " << area << std::endl;

	system("PAUSE");
	return 0;
}