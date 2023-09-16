#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <math.h>

struct dates
{
	int year, month, day;
};
void loadDates(dates a[], int& n);
void sortDatesInAscendingOrder(dates a[], int n);
void saveDates(dates a[], int n);

#endif


