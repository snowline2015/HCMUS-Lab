/*
MSSV : 19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9
*/
#include "Function.h"

int main()
{
	int n;
	fraction a[100];
	fraction max;
	loadFraction(a, n);
	maxFraction(a, n, max);
	saveFraction(a, n, max);
	return 0;
}