/*
MSSV : 19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9
*/
#include "Function.h"

int main()
{
	int n;
	point a[100];
	loadPoint(a, n);
	sortPointInDescendingOrder(a, n);
	savePoint(a, n);
	return 0;
}