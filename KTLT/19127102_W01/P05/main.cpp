/*
MSSV : 19127102
Họ tên : Võ Hoàng Gia Bảo
Lớp : 19CLC9
*/
#include "Function.h"

int main()
{
	int n;
	dates a[100];
	loadDates(a, n);
	sortDatesInAscendingOrder(a, n);
	saveDates(a, n);
	return 0;
}