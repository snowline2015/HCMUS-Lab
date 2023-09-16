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
	loadFraction(a, n);
	sortFractionInAscendingOrder(a, n);
	saveFraction(a, n);
	return 0;
}