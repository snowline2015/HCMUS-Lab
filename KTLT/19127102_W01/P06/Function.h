#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <math.h>
#include <string.h>

struct products
{
	int id, stock;
	long int price;
	char name[101];
};
void loadProducts(products a[], int& n);
void total(products a[], int n, long int &money);
void saveProducts(products a[], int n, long int money);

#endif


