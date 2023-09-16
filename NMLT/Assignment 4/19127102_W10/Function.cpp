#include "function.h"


void inputAPoint(point& coord)
{
	std::cout << "Input a point's coordinate : ";
	std::cin >> coord.x >> coord.y;
}

void outputAPoint(point coord)
{
	std::cout << "(" << coord.x << ", " << coord.y << ")" << std::endl;
}

double distance(point coord1, point coord2)
{
	double S = sqrt(pow(coord2.x - coord1.x, 2) + pow(coord2.y - coord1.y, 2));
	return S;
}

int findQuadrantOFAPoint(point coord)
{
	int ans;
	if (coord.x > 0 && coord.y > 0) ans = 1;
	if (coord.x > 0 && coord.y < 0) ans = 2;
	if (coord.x < 0 && coord.y > 0) ans = 4;
	if (coord.x < 0 && coord.y < 0) ans = 3;
	return ans;
}

void inputTriangle(triangle &coord)
{
	std::cout << "Input 3 points' coordinate of a triangle" << std::endl;
	std::cout << "Input point 1 : ";
	std::cin >> coord.a.x >> coord.a.y;
	std::cout << "Input point 2 : ";
	std::cin >> coord.b.x >> coord.b.y;
	std::cout << "Input point 3 : ";
	std::cin >> coord.c.x >> coord.c.y;
}

void outputTriangle(triangle coord)
{
	std::cout << "Point 1 (" << coord.a.x << ", " << coord.a.y << ")" << std::endl;
	std::cout << "Point 2 (" << coord.b.x << ", " << coord.b.y << ")" << std::endl;
	std::cout << "Point 3 (" << coord.c.x << ", " << coord.c.y << ")" << std::endl;
}

void findPerimeterAndArea(triangle coord, double &area, double &perimeter)
{
	double distance1, distance2, distance3;
	distance1 = sqrt(pow(coord.a.x - coord.b.x, 2) + pow(coord.a.y - coord.b.y, 2));
	distance2 = sqrt(pow(coord.b.x - coord.c.x, 2) + pow(coord.b.y - coord.c.y, 2));
	distance3 = sqrt(pow(coord.a.x - coord.c.x, 2) + pow(coord.a.y - coord.c.y, 2));
	perimeter = distance1 + distance2 + distance3;
	double temp = perimeter / 2.0;
	area = sqrt(temp * (temp - distance1) * (temp - distance2) * (temp - distance3));
}