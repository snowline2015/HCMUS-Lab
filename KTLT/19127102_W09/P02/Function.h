#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>

struct Date {
	int day, month, year;
};
void inputArray(int arr[], int& n);
void saveBin(int arr[], int n);
void loadBin(int arr[]);
void findNewestDate(Date a[], int arr[]);

#endif