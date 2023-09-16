#include "Function.h"

int main()
{
	int n;
	long int money;
	products a[100];
	loadProducts(a, n);
	total(a, n, money);
	saveProducts(a, n, money);
	return 0;
}