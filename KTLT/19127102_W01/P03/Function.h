#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <math.h>

struct point
{
	int x, y;
};
void loadPoint(point a[], int& n);
void sortPointInDescendingOrder(point a[], int n);
void savePoint(point a[], int n);

#endif

