#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <iostream>
#include <math.h>

struct point {
	double x, y;
};

struct triangle {
	point a, b, c;
};

void inputAPoint(point& coord);
void outputAPoint(point coord);
double distance(point coord1, point coord2);
int findQuadrantOFAPoint(point coord);
void inputTriangle(triangle& coord);
void outputTriangle(triangle coord);
void findPerimeterAndArea(triangle coord, double& area, double& perimeter);

#endif
