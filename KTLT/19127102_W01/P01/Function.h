#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

struct fraction
{
	int numberator, denominator;
};
void loadFraction(fraction a[], int& n);
void maxFraction(fraction a[], int n, fraction& max);
void saveFraction(fraction a[], int n, fraction max);

#endif