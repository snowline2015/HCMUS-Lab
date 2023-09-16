#include "Function.h"

int main()
{
	int n;
	circles a[100];
	double sum;
	loadCircles(a, n);
	sumCirclesArea(a, n, sum);
	saveCircles(a, n, sum);
	return 0;
}