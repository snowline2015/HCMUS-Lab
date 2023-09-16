#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#define PI 3.14

#include <iostream>
#include <math.h>

struct circles {
	int x, y;
	double radius;
};
void loadCircles(circles a[], int& n);
void sumCirclesArea(circles a[], int n, double &sum);
void saveCircles(circles a[], int n, double sum);
#endif
